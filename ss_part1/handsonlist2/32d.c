/*reg no- MT2022112 name - Shubhanshi Bhandari

d. remove the created semaphore

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


int main(){
struct sembuf semOp; 


int keysem,semid;
union semun arg;
keysem = ftok(".",'b');
semid=semget(keysem,1,0);

semctl(semid, 0, IPC_RMID);

}
