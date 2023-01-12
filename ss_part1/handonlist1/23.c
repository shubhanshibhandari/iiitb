/* name - shubhanshi bhandari , reg no- MT2022112
 Write a program to create a Zombie state of the running program.
 */
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

  if (fork() == 0){
        printf(" check the process status of child using :%d\n",getpid());
         exit(0);
         }
  
    // parent process because return value non-zero.
    else
      printf("process id of  Parent:%d\n",getpid());
      sleep(50);
}

