/*reg no- MT2022112 name - Shubhanshi Bhandari
24. Write a program to create a message queue and print the key and message queue id.
*/
#include<unistd.h>
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>

int main(){
  int msgid;
  key_t key;
  key=ftok(".",'a');
  msgid=msgget(key,IPC_CREAT|IPC_EXCL|0744);
  printf("key value in hex=0x%0x\n",key);
  printf("Message queue id =%d\n",msgid);
}
