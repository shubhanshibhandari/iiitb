/*reg no- MT2022112 name - Shubhanshi Bhandari
8. Write a separate program using signal system call to catch the following signals.
d. SIGALRM (use alarm system call)
*/


#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void handler(){
    printf("SIGALRM catched via alarm system call\n");
    exit(EXIT_SUCCESS);
}

int main(){
    signal(SIGALRM, handler);
    alarm(3);
    sleep(8);
    return 0;
}
