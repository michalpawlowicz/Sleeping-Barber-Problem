#include <time.h>
#include "barber.h"

struct timespec spec;
long            ms; // Milliseconds
time_t          s;  // Seconds

//waiting customers in waiting room, excluding customer already on barber sit
sem_t* customers;

// number of barbers 0 or 1
sem_t* barber;

sem_t* mutex;

sem_t* barber_sem;

//Shared memory descriptor
int shm;
int* queue_p;
int shm_wr_id;
int* waitint_room_size;

void sig_handler(int signum);
void atexit_h(void);

void print_time(){
    clock_gettime(CLOCK_REALTIME, &spec);
    s = spec.tv_sec;
    ms = round(spec.tv_nsec / 1.0e6);
    printf("%"PRIdMAX".%03ld\n", (intmax_t) s, ms);
}

void barber_p(){
    while(1){
        if(sem_trywait(customers) == -1) {
            if (errno == EAGAIN) {
                sem_wait(mutex);
                printf("Barber is going to sleep! ");
                print_time();
                sem_post(barber); //// !!!!
                sem_post(mutex);
                sem_wait(customers);
            }
        }

        pid_t pid;
        sem_wait(mutex);
            pid = pop(queue_p);
            printf("Cutting customer with id: %d ", pid);
            print_time();
            union sigval x;
            sigqueue(pid, SIGRTMIN, x);
            printf("Finished cutting customer %d ", pid);
            print_time();
        sem_post(mutex);

    }
}


int main(int argc, char** argv){

    if(argc != 2){
        printf("Specify wating room size\n");
        exit(0);
    }

    // signals handlers
    signal(SIGINT, sig_handler);
    signal(15, sig_handler);
    atexit(atexit_h);

    // Waiting room size, shared memory
    if((shm_wr_id = shm_open(SHARED_MEMORY_NAME_WR, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)) == -1){
        perror("Shared memory error - wr");
        exit(0);
    }

    if(ftruncate(shm_wr_id, sizeof(int)) == -1){
        perror("ftruncate wr error");
        exit(0);
    }

    if((waitint_room_size = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_wr_id, 0)) == MAP_FAILED){
        perror("wr mmap error");
        exit(0);
    }

    *waitint_room_size = atoi(argv[1]);

    //shared memory for queue
    if((shm = shm_open(SHARED_MEMORY_NAME, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)) == -1){
        perror("Shared memory error");
        exit(0);
    }

    if(ftruncate(shm, QUEUE_SIZE_BYTES) == -1){
        perror("ftruncate error");
        exit(0);
    }

    if((queue_p = (int*)mmap(NULL, QUEUE_SIZE_BYTES, PROT_READ | PROT_WRITE, MAP_SHARED, shm, 0)) == MAP_FAILED){
        perror("mmap error");
        exit(0);
    }

    create_queue(queue_p);

    if((customers = sem_open(CUSTOMERS_SEM_NAME, O_CREAT, S_IRUSR | S_IWUSR, 0)) == SEM_FAILED){
        perror("Customers semaphore error");
        exit(0);
    }

    if((barber = sem_open(BARBER_SEM_NAME, O_CREAT, S_IRUSR | S_IWUSR, 0)) == SEM_FAILED){
        perror("Customers semaphore error");
        exit(0);
    }


    if((mutex = sem_open(MUTEX_SEM_NEMA, O_CREAT, S_IRUSR | S_IWUSR, 1)) == SEM_FAILED){
        perror("Customers semaphore error");
        exit(0);
    }


    printf("Barber opens hair salon\n");
    barber_p();

    return 0;
}


void sig_handler(int signum){
    exit(0);
}

void atexit_h(void){
    sem_close(customers);
    sem_close(barber);
    sem_close(mutex);
    sem_close(barber_sem);

    sem_unlink(CUSTOMERS_SEM_NAME);
    sem_unlink(BARBER_SEM_NAME);
    sem_unlink(MUTEX_SEM_NEMA);
    sem_unlink("/barber");

    munmap(queue_p, QUEUE_SIZE_BYTES);
    shm_unlink(SHARED_MEMORY_NAME);

    munmap(waitint_room_size, sizeof(int));
    shm_unlink(SHARED_MEMORY_NAME_WR);
}