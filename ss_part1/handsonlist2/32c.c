
/*reg no- MT2022112 name - Shubhanshi Bhandari
32. Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore

*/



#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/sem.h>
union semun{
 int val;
 struct semid_ds *buf;
 unsigned short int *array;
 
};


int main(){
struct sembuf semOp; 

// use 31_b.c to create semaphore with arg val = 2
int keysem,semid;
union semun arg;
keysem = ftok(".",'b');
semid=semget(keysem,1,0);
 char data[1000];


    int fd;
    
    fd = open("file.txt", O_RDONLY);
//locking semaphore
    semOp.sem_num = 0;
    semOp.sem_flg = SEM_UNDO;
    
    printf("Press enter to obtain lock for the critical section!\n");
    getchar();
    
    
    semOp.sem_op = -1;
    semop(semid, &semOp, 1);
    
    int nread = read(fd, &data, 1000);
    write(1,&data,nread);
    
    printf("\n\nPress enter key to exit critical section!\n");
    getchar();

    semOp.sem_op = 1;
    semop(semid,&semOp, 1);
    
    close(fd);
    
}
