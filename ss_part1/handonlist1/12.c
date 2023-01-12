/*Reg no- MT2022112 name - Shubhanshi Bhandari
12. Write a program to find out the opening mode of a file. Use fcntl.
*/


#include <unistd.h>
#include <fcntl.h>
#include<sys/types.h>
#include<stdio.h>
int main(){
	int fd;
	int flags;
	fd=open("file_for_ques11.txt",O_RDWR | O_APPEND);
	flags= fcntl(fd,F_GETFL);
        flags = flags  & O_ACCMODE;
    if      (flags  == O_RDONLY)   printf("read only");
    else if (flags  == O_WRONLY)   printf("write only");
    else if (flags  == O_RDWR)     printf("read write");
	return 0;
}
