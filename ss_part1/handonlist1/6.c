/*Reg no.- MT2022112 name- Shubhanshi Bhandari
6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls*/

#include<stdio.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<stdlib.h>
int main(){
char buff[100];
int nread=read (0,buff,100);
write(1,buff,nread);
}

