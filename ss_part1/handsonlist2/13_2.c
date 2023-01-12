
/*reg no- MT2022112 name - Shubhanshi Bhandari
13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(){
    int pid;
    printf("enter the pid of the process to kill:\n");
    scanf("%d",&pid);
    kill(pid, SIGKILL);
    return 0;
}
