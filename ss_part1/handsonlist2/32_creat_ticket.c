#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

int main(){
   struct tic{
   int ticket_no;
   };
   struct tic *ticket;
   int key,shmid,n;
   key=ftok(".",'c');
   shmid=shmget(key,sizeof(ticket),IPC_CREAT|0744);
   //writing data into shared memory
   ticket=(struct tic*)shmat(shmid,0,0);
   printf("enter text for shared memory: ");
   scanf(" %d",&n);
   ticket->ticket_no=n;
   printf("current ticket no set to:%d",ticket->ticket_no); 
   }
