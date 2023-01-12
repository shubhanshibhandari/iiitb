/*reg no.-MT2022112 Name- Shubhanshi Bhandari
3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
*/


#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
int main (void){
int fd;

fd = creat ("file_ques.txt", 0744);
perror("file creation was :");
printf("%d\n",fd);
}


