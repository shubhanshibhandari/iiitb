/*reg no- MT2022112 name - Shubhanshi Bhandari
27. Write a program to receive messages from the message queue.
a. with 0 as a flag

*/
// use 26.c to send the meassage//
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
        int msgtype;
	key=ftok(".",'a');
	msgid=msgget(key,0);
	printf("enter message type: ");
	scanf("%d",&msgtype);
//	printf("enter the message text: ");
//	scanf("%[\n]",mq.message);
	//nread=read(0,mq.message,80);
//	size=strlen(mq.message);
	msgrcv(msgid,&mq,sizeof(mq.message),msgtype,0);
        printf("recevied message %s",mq.message);

}
