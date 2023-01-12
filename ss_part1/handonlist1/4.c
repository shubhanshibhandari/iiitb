/*Reg no. - MT2022112 Name- Shubhanshi Bhandari
4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
*/
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

int main (void){
int fd;
time_t t = time(NULL);
char *arr=ctime(&t);
fd = open ("file_ques.txt", O_RDWR | O_EXCL |O_APPEND);
perror("file opening   was :");
char *buff="You have opened file_ques.text ";
write(fd,buff,30);
write(fd,arr,strlen(arr));

}


