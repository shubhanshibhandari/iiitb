/* 
reg no- MT2022112 name - Shubhanshi Bhandari

Question : Write a program to print a message queue's (use `msqid_ds` and `ipc_perm` structures)
    1. Access permission 
    2. `uid`, `gid` 
    3. Time of last message sent and received 
    4. Time of last change in the message queue
    5. Size of the queue 
    6. Number of messages in the queue
    7. Maximum number of bytes allowed
    8. PID of the `msgsnd` and `msgrcv`
*/

#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h>   
#include <stdio.h>    
#include <unistd.h> 
#include <sys/time.h>
#include<time.h>

void main()
{
    key_t Key;                  
    int msgid;              
    struct msqid_ds msginfo; 
    int msgctlStatus;                 

    Key = ftok(".",' a');

 

    msgid = msgget(Key,0);


    printf("Key: %d\n", Key);
    printf("Message Queue Identifier: %d\n\n",msgid);

    msgctl(msgid, IPC_STAT, &msginfo);

 
    printf("Access Permission: %od\n", msginfo.msg_perm.mode);
    printf("UID: %d\n", msginfo.msg_perm.uid);
    printf("GID: %d\n", msginfo.msg_perm.gid);
    printf("Time of last message sent: %s\n", ctime(&msginfo.msg_stime));
    printf("Time of last message received: %s\n", ctime(&msginfo.msg_rtime));
    printf("Size of queue: %ld\n", msginfo.__msg_cbytes);
    printf("Number of messages in the queue: %ld\n", msginfo.msg_qnum);
    printf("Maximum number of bytes allowed in the queue: %ld\n", msginfo.msg_qbytes);
    printf("PID of last sent message: %d\n", msginfo.msg_lspid);
    printf("PID of last received message: %d\n", msginfo.msg_lrpid);
}
 
