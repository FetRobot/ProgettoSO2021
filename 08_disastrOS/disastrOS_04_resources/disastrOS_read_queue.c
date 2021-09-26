#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"
#include "disastrOS_structures.h"

void readQueue(){

  printf("READ\n");

  //lf I read the input parameters
	queue* q = running->syscall_args[0];
	char* s = running->syscall_args[1];
	int size = running->syscall_args[2];

  int i=0;
  //lf if the available space to read is 0: return 0
  //lf this way I can tell I read 0 characters
  if(q->readingSpace==0){
      running->syscall_retvalue=0;
      printQueue(q);
      return;
  }
  //lf until there's space for reading and until I haven't finished reading the characters I need to read
  while(i<size && q->readingSpace>0){
      //lf I read from the queue and I copy the read character in the string 's'
      s[i]=q->buffer[q->readingIndex];
      //lf I put back the read character inside the queue with the default value: so I can visually see how the queue evolves
      q->buffer[q->readingIndex]='_';
      //lf I update the input parameters
      q->readingIndex=(q->readingIndex+1)%100;
      q->readingSpace--;
      q->writingSpace++;
      i++;
    }
    printQueue(q);
    running->syscall_retvalue=i;
}
