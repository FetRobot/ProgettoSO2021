#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"
#include "disastrOS_structures.h"

void writeQueue(){

  printf("WRITE\n");

  //lf I read and store the input paremeters
	queue* q = running->syscall_args[0];
	char* s = running->syscall_args[1];
	int size = running->syscall_args[2];

  int i=0;
  //lf if the available space is 0: return 0
  //lf this way I can tell I wrote 0 characters
  if(q->writingSpace==0) {
      running->syscall_retvalue=0;
      printQueue(q);
      return;
  }
  //lf until there's space for writing on and until I haven't finished writing the characters I need to write
  while(i<size && q->writingSpace>0){
      q->buffer[q->writingIndex]=s[i]; //lf I write in the queue
      //lf and I update the parameters accordingly
      i++;
      q->writingIndex=(q->writingIndex+1)%100;
      q->writingSpace--;
      q->readingSpace++;
  }
  printQueue(q);
  running->syscall_retvalue=i;

}
