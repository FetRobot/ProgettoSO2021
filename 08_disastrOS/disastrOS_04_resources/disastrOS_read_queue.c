#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"
#include "disastrOS_structures.h"

void readQueue(){

  printf("READ\n");

	queue* q = running->syscall_args[0];
	char* s = running->syscall_args[1];
	int size = running->syscall_args[2];

  int i=0;
  if(q->readingSpace==0){
      running->syscall_retvalue=0;
      printQueue(q);
      return;
  }
  while(i<size && q->readingSpace>0){
      s[i]=q->buffer[q->readingIndex];
      q->buffer[q->readingIndex]='_';
      q->readingIndex=(q->readingIndex+1)%100;
      q->readingSpace--;
      q->writingSpace++;
      i++;
    }
    printQueue(q);
    running->syscall_retvalue=i;
}
