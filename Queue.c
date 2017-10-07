#include "Queue.h"

// first byte HEAD
// second byte TAIL
// third byte SIZE
// since fourth byte ARRAY

void create_queue(int* p){
    *p = 0;
    *(p + 1) = 0;
    *(p + 2) = QUEUE_SIZE_NUM;
    for(int i=0; i < QUEUE_SIZE_NUM - 3; i++){
        *(p + 3 + i) = 0;
    }
}

int get_head(int* p){
    return *p;
}

int get_tail(int *p){
    return *(p+1);
}

int get_size(int* p){
    return *(p+2);
}

int is_empty(int* p){
    return get_head(p) == get_tail(p);
}

int pop(int* p){
    int tmp = *(p + 3 + get_head(p));
    *(p + 3 + get_head(p)) = 0;
    (*p)++;
    if(get_head(p) == QUEUE_SIZE_NUM - 3) *p = 0;
    return tmp;
}

int push(int* p, int val){
    *(p + 3 + get_tail(p)) = val;
    (*(p+1))++;
    if(get_tail(p) == get_size(p) - 3){
        if(get_head(p) != 0) {
            *(p + 1) = 0;
        }
    }
}

void printf_q(int* p){
    printf("%d | %d : ", get_head(p), get_tail(p));
    for(int i=0; i < QUEUE_SIZE_NUM - 3; i++){
        printf(" %d ", *(p + 3 + i));
    }
    printf("\n");
}