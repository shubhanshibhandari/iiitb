/*reg no- MT2022112 name - Shubhanshi Bhandari
30. Write a program to create a shared memory.
a. write some data to the shared memory


*/

#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

int main(){
   int key,shmid;
   char *spointer;
   key=ftok(".",'b');
   shmid=shmget(key,1024,IPC_CREAT|0744);
   //writing data into shared memory
   spointer=shmat(shmid,0,0);
   printf("enter text for shhred memory: ");
   scanf(" %[^\n]",spointer);
 
   
   
   
}
