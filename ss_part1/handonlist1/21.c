/* name - shubhanshi bhandari , reg no- MT2022112
 Write a program, call fork and print the parent and child process id.
 */
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
int main(){
  if (fork() == 0)
        printf(" process id of  Child :%d\n",getpid());

  
    // parent process because return value non-zero.
    else
        printf("process id of  Parent:%d\n",getpid());
   
}

