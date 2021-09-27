# Progetto Sistemi Operativi

## Message queues in disastrOS | Leonardo Fettucciari 1858879


### WHAT
Nel seguente progetto è stato implementato un meccanismo di IPC mediante message queues, partendo da uno stub del progetto "disastrOS".

### HOW
1. Nei file disastrOS_structures.c e disastrOS_structures.h sono state inserite le strutture per le code, la lista delle code e le funzioni per aprire e/o chiudere le code.
1. Quando viene chiamata la system call disastrOS_write_queue() la routine eseguita è situata nel file disastrOS_write_queue.c
1. Quando viene chiamata la system call disastrOS_read_queue() la routine eseguita è situata nel file disastrOS_read_queue.c
1. Tutti i file modificati sono comprendenti di commenti preceduti dal prefisso //lf e sono i seguenti:
    - disastOS.c
    - disastrOS.h
    - disastrOS_constants.h
    - disastrOS_syscalls.h
    - disastrOS_test.c   

### HOW TO RUN
Una volta entrati nella directory 08_disastrOS/disastOS_04_resources/ compiliamo con il comando
```
    make
```
dopodichè eseguiamo il test con il comando:
```
    ./disastrOS_test
```
