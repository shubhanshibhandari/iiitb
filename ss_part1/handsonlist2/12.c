/*reg no- MT2022112 name - Shubhanshi Bhandari
12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.

*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
#include<wait.h>

int main(){

     if(!fork()){
          
            printf("This is child process with id %d and parent has id %d\n",getpid(), getppid());
            sleep(1);
            printf("Sending SIGKILL signal to the parent process...");
            kill(getppid(), SIGKILL);
            printf("Parent Process killed..\n");
            sleep(1);
            printf("This is child process with id %d and parent has id %d\n",getpid(), getppid());
            exit(EXIT_SUCCESS);

            }
     else{
            printf("This is parent process with id %d\n",getpid());
            wait(0);
    }

    return 0;
}
