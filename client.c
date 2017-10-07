#include <time.h>
#include "barber.h"

int S = 5;

struct timespec spec;
long            ms; // Milliseconds
time_t          s;  // Seconds


int CUSTOMERS = 100;

//waiting customers in waiting room, excluding customer already on barber sit
sem_t* customers;

// number of barbers 0 or 1
sem_t* barber;

sem_t* mutex;

//Shared memory descriptor
int shm;
int shm_wr;
int* wating_room_size;
int* queue_p;

void sig_handler(int signum);
void atexit_h(void);

int waiting = 0;

void sig_usr1(int signum){
    waiting = 1;
    return;
}

void print_time(){
    clock_gettime(CLOCK_REALTIME, &spec);
    s = spec.tv_sec;
    ms = round(spec.tv_nsec / 1.0e6);
    printf("%"PRIdMAX".%03ld\n", (intmax_t) s, ms);
}

int main(int argc, char** argv){

    if(argc != 3){
        printf("Specify clients number and haircut number\n");
        return 0;
    } else{
        CUSTOMERS = atoi(argv[1]);
        S = atoi(argv[2]);
    }

    signal(15, sig_handler);

    struct sigaction act;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGRTMIN);
    act.sa_handler = sig_usr1;
    sigaction(SIGRTMIN, &act, NULL);

    //shared memory for wating room size
    if((shm_wr = shm_open(SHARED_MEMORY_NAME_WR, O_RDWR, S_IRUSR | S_IWUSR)) == -1){
        perror("Shared memory error");
        exit(0);
    }

    if((wating_room_size = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_wr, 0)) == MAP_FAILED){
        perror("mmap error");
        exit(0);
    }

    //shared memory for queue
    if((shm = shm_open(SHARED_MEMORY_NAME, O_RDWR, S_IRUSR | S_IWUSR)) == -1){
        perror("Shared memory error");
        exit(0);
    }

    if((queue_p = (int*)mmap(NULL, QUEUE_SIZE_BYTES, PROT_READ | PROT_WRITE, MAP_SHARED, shm, 0)) == MAP_FAILED){
        perror("mmap error");
        exit(0);
    }

    if((customers = sem_open(CUSTOMERS_SEM_NAME, S_IRUSR | S_IWUSR)) == SEM_FAILED){
        perror("Customers semaphore error");
        exit(0);
    }

    if((barber = sem_open(BARBER_SEM_NAME, S_IRUSR | S_IWUSR)) == SEM_FAILED){
        perror("Customers semaphore error");
        exit(0);
    }


    if((mutex = sem_open(MUTEX_SEM_NEMA, S_IRUSR | S_IWUSR)) == SEM_FAILED){
        perror("Customers semaphore error");
        exit(0);
    }

    pid_t pid;
    for (int i = 0; i < CUSTOMERS; i++){
            pid_t pid;
            if ((pid = fork()) == -1) {
                perror(NULL);
                exit(0);
            } else if (pid == 0) {
                for(int l=0; l<S; l++) {
                    sem_wait(mutex);

                    int val;
                    sem_getvalue(customers, &val);

                    if(val >= *wating_room_size){
                        printf("Queue is full! Going back %d ", getpid());
                        print_time();
                        sem_post(mutex);
                        continue;
                    }

                    sem_getvalue(barber, &val);
                    if(val != 0){
                        printf("Waking up barber %d ", getpid());
                        print_time();
                        sem_wait(barber);
                    } else {
                        printf("Waiting in queue: %d ", getpid());
                        print_time();
                    }

                    push(queue_p, getpid());
                    fflush(stdout);
                    sem_post(customers);
                    sem_post(mutex);
                    while (!waiting);
                    printf("Got haircut %d ", getpid());
                    print_time();
                    waiting=0;
                }
                exit(0);
            }
    }

    pid_t wpid;
    int status;
    while(wait(&status) > 0);

    sem_close(customers);
    sem_close(barber);
    sem_close(mutex);

    munmap(queue_p, QUEUE_SIZE_BYTES);
    munmap(wating_room_size, sizeof(int));

    return 0;
}

void sig_handler(int signum){

    sem_close(customers);
    sem_close(barber);
    sem_close(mutex);

    munmap(queue_p, QUEUE_SIZE_BYTES);
    munmap(wating_room_size, sizeof(int));

    exit(0);
}
