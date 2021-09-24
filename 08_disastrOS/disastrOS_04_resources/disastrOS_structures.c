#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disastrOS_structures.h"

queueList queueListInit(){
    queueList ql;
    ql.queueNum=0;
    ql.first=NULL;
    return ql;
}

queue* openQueue(char* s){
    queue* ret;
    queue* aux = list.first;

    while(aux){
        if(aux->name==s){
            aux->refNum++;
            return aux;
        }
        aux=aux->next;
    }

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

    if(aux->name==s){
        aux->refNum--;
        if(aux->refNum==0){
            list.first=aux->next;
            list.queueNum--;
        }
    }

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
