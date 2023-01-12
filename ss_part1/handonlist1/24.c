/* name - shubhanshi bhandari , reg no- MT2022112
 Write a program to create a orphan process
 */
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

  if (fork() == 0){
        printf(" child parent before being orphan :%d\n",getppid());
         sleep(10);
         printf("child parent after being orphan:%d\n",getppid());
                
  }
  
    // parent process because return value non-zero.
    else{
      sleep(1);
      printf("process id of  Parent:%d\n",getpid());
      exit(0);
    }
}

