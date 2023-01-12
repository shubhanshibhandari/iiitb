/* name - shubhanshi bhandari , reg no- MT2022112
1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void){
symlink("source","softlink");
perror("return softlink:");
}
