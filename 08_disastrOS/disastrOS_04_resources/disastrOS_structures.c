#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disastrOS_structures.h"

//lf list of queues initializer
queueList queueListInit(){
    queueList ql;
    ql.queueNum=0;
    ql.first=NULL;
    return ql;
}

//lf we try to open the queue 's' as passed as argument:
//lf if it exists its pointer is returned else it's created first
queue* openQueue(char* s){
    queue* ret;
    queue* aux = list.first;

    //lf here I scan the whole list, if I find a queue with the given name
    //lf I return its pointer
    while(aux){
        if(aux->name==s){
            aux->refNum++;
            return aux;
        }
        aux=aux->next;
    }

    //lf else I create the given queue and add it on top of the list, then I return its pointer
    queue* q = (queue*) malloc(sizeof(struct queue));
    q->name=s;
    q->refNum=1;
    q->writingSpace=100;
    q->readingSpace=0;
    q->writingIndex=0;
    q->readingIndex=0;
    memset(q->buffer,'_',100);
    q->next=list.first;
    q->prev=NULL;
    list.first=q;
    list.queueNum++;

    return q;
}

void closeQueue(char* s){
    queue* tmp;
    queue* aux=list.first;

    //lf queue in first position?
    if(aux->name==s){
        aux->refNum--;
        if(aux->refNum==0){
            list.first=aux->next;
            list.queueNum--;
        }
    }

    //lf else we scan the list, when we find it we decrement the refNum:
    //lf when it hits 0 we remove it from the list
    while(aux){
        tmp=aux->next;
        if(tmp && tmp->name==s){
            tmp->refNum--;
            if(tmp->refNum==0){
                aux->next=tmp->next;
                list.queueNum--;
                break;
            }
        }
        aux=aux->next;
    }
}

//lf print currently open queues
void printQueueList(){
    printf("queueNum: %d\n",list.queueNum);
    queue* aux=list.first;

    while(aux){
        printf("%s: ",aux->name);
        aux=aux->next;
    }
    if(aux==NULL) printf("null\n");
}

//lf print a queue' structure
void printQueue(queue* aux){
    printf("name: %s   refNum:%d   writingSpace:%d   writingIndex:%d   readingSpace:%d   readingIndex:%d\n",
                                    aux->name,
                                    aux->refNum,
                                    aux->writingSpace,
                                    aux->writingIndex,
                                    aux->readingSpace,
                                    aux->readingIndex);
    printf("%s\n",aux->buffer);
}
