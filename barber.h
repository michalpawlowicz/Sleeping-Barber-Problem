//
// Created by michal on 4/29/17.
//

#ifndef LAB2_BARBER_H
#define LAB2_BARBER_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <signal.h>
#include "Queue.h"
#include <signal.h>
#include <zconf.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>
#include <math.h>



const int PROJ_ID = 3;
const int SEM_PROJ_ID = 4;
const size_t SHM_SIZE = sizeof(int);
const size_t WAITING_ROOM_SIZE = 3;


const char CUSTOMERS_SEM_NAME[] = "/customers";
const char BARBER_SEM_NAME[] = "/barbers";
const char MUTEX_SEM_NEMA[] = "/mutex";
const char SHARED_MEMORY_NAME[] = "/shared_mem";
const char SHARED_MEMORY_NAME_WR[] = "/waiting_room";


#endif //LAB2_BARBER_H
