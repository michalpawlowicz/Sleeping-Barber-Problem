//
// Created by michal on 5/2/17.
//

#ifndef LAB2_QUEUE_H
#define LAB2_QUEUE_H

#include <stdio.h>

// Including:
// first byte HEAD
// second byte TAIL
// third byte SIZE
// since fourth byte ARRAY

#define QUEUE_SIZE_NUM 10000
#define QUEUE_SIZE_BYTES (sizeof(unsigned int) * QUEUE_SIZE_NUM)

void create_queue(int* p);
int pop(int* p);
int push(int* p, int val);
void printf_q(int* p);


#endif //LAB2_QUEUE_H
