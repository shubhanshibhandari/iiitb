#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(void)
{
int fd;
struct{
int ticket;
}reg;

 reg.ticket=10;
 fd=open("db",O_CREAT|O_RDWR,0744);
 write(fd,&reg,sizeof(reg));
 close(fd);
 fd = open("db",O_RDONLY);
 read(fd,&reg,sizeof(reg));
 printf("ticket no :%d\n",reg.ticket);
 close(fd);
}
