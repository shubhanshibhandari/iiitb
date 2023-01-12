/*reg no- MT2022112 name - Shubhanshi Bhandari
32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
since i have written ticket booking using shared memory only therefor no separate program for 32b

*/

#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/sem.h>
union semun{
 int val;
 struct semid_ds *buf;
 unsigned short int *array;

};
struct tic{
   int ticket_no;
   };

int main(){
   //create shared memory and intial ticket no using 32_create_tickec.c
   struct tic *ticket;
   //shared memory requirement
   int key,shmid,n;
   key=ftok(".",'c');
   
   // semaphore requirement
   // create semaphore using 31_a.c
   int keysem ,semid;
   
   union semun arg;
   keysem = ftok(".",'a');
   semid= semget(keysem,1,0);
   
   while(1)
{   int choice;
   printf("enter 1 for read\n");
   printf("enter 2 for update\n");
   scanf("%d",&choice);
   
   if(choice==1 ){
   if (semctl(semid,0,GETVAL) ){
   shmid=shmget(key,sizeof(ticket),0);
   //writing data into shared memory
   //ticket=(struct tic*)shmat(shmid,0,0);
   
   
   /*printf("enter text for shared memory: ");
   scanf(" %d",&n);
   ticket->ticket_no=n;
   */
   //printf("current ticket no set to:%d",ticket->ticket_no); 
   
   
   //writing data into shared memory
   ticket=(struct tic*)shmat(shmid,0,SHM_RDONLY);
   printf("current tickect no: %d\n",ticket->ticket_no);
  } 
   //printf("enter text to shared memory: ");
   //scanf(" %d",&ticket->ticket_no);
  else
  printf("please wait other user is writing\n");
 
 }
 
 else{ 
    if(choice==2)
   {

    struct sembuf semOp; // Defines the operation on the semaphore
    semOp.sem_num = 0;
    semOp.sem_flg = SEM_UNDO;
    
    
    semOp.sem_op = -1;
    semop(semid, &semOp, 1);
    
    shmid=shmget(key,sizeof(ticket),0);
    ticket=(struct tic*)shmat(shmid,0,0);
    //ticket=(struct tic*)shmat(shmid,0,0);
    
    printf("current tickect no: %d\n",ticket->ticket_no);
    int curr= ticket->ticket_no;
    printf("enter no of tickects to book \n");
    scanf(" %d",&n);
    ticket->ticket_no+=n;
    printf("new ticket no set:%d",ticket->ticket_no);
    
   
    semOp.sem_op = 1;
    semop(semid, &semOp, 1);
    printf("Critical section is now unlocked!\n");
 }
  else{
  printf("enter valid choice\n");
  } 
 }
 }
}
   

