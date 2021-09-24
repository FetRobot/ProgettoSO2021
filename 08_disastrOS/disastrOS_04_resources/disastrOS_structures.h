#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue queue;
typedef struct queueList queueList;

typedef struct queue{
    char* name;
    int refNum;
    int writingSpace;
    int readingSpace;
    int readingIndex;
    int writingIndex;
    char buffer[100];
    queue* next;
    queue* prev;
}queue;

typedef struct queueList{
    int queueNum;
    queue* first;
}queueList;

queueList list;

queueList queueListInit();

queue* openQueue(char* s);

void closeQueue(char* s);
