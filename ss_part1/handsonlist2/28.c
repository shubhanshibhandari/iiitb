/*reg no- MT2022112 name - Shubhanshi Bhandari
28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
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

    Key = ftok(".",' a');

 

    msgid = msgget(Key,0);


    printf("Key: %d\n", Key);
    printf("Message Queue Identifier: %d\n\n",msgid);

    msgctl(msgid, IPC_STAT, &msginfo);

 
    printf("current Access Permission: %o\n", msginfo.msg_perm.mode);
    msginfo.msg_perm.mode=0764;
    msgctl(msgid,IPC_SET,&msginfo);
    printf("new Access Permission: %o\n", msginfo.msg_perm.mode);
   
}
 
