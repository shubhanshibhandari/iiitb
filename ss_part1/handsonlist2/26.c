/*reg no- MT2022112 name - Shubhanshi Bhandari

26. Write a program to send messages to the message queue. Check $ipcs -q
*/


#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int msgid,size,nread;
	key_t key;
	struct msg{
		long int mtype;
		char message[80];
	}mq;
        
	key=ftok(".",'a');
	msgid=msgget(key,0);
	printf("enter message type: ");
	scanf("%ld",&mq.mtype);
	//printf("%ld",mq.mtype);
	printf("enter the message text: ");
	scanf(" %[^\n]",mq.message);
	//printf("%s",mq.message);
	//nread=read(0,mq.message,80);
	//printf("%s",mq.message);	
	size=strlen(mq.message);
	//printf("%d",size);
	msgsnd(msgid,&mq,size+1,0);
}
