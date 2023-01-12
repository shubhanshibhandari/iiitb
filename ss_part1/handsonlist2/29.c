/* 
reg no- MT2022112 name - Shubhanshi Bhandari
29. Write a program to remove the message queue.


*/

#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h>   
#include <stdio.h>    
#include <unistd.h> 
#include <sys/time.h>
#include<time.h>
#include<fcntl.h>
#include<sys/stat.h>
void main()
{
    key_t Key;                  
    int msgid;              
    struct msqid_ds msginfo; 
   // int msgctlStatus;                 
   // use 24.c to actually create the msg queue first
    Key = ftok(".",' a');

 

    msgid = msgget(Key,0);


    printf("Key: %d\n", Key);
    printf("Message Queue Identifier: %d\n\n",msgid);

    msgctl(msgid, IPC_RMID,NULL);

 
   
}
 
