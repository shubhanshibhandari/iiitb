/*reg no- MT2022112 name - Shubhanshi Bhandari
31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore

*/


#include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>

union semun{
 int val;
 struct semid_ds *buf;
 unsigned short int *array;

};

int main (){
 union semun arg;
 int key ,semid;
 key = ftok(".",'b');
 semid= semget(key,1,IPC_CREAT | 0744);
 arg.val=2;
 semctl(semid,0,SETVAL,arg);
 
}
