/*reg no- MT2022112 name - Shubhanshi Bhandari
30. Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.
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
   char *srdonly;
   key=ftok(".",'b');
   shmid=shmget(key,1024,0);
   //writing data into shared memory
   srdonly=shmat(shmid,0,SHM_RDONLY);
   printf("enter text fron shhred memory: %s\n",srdonly);
   printf("enter text to shared memory: ");
   scanf(" %[^\n]",srdonly);
 
 }
