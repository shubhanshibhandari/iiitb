/*reg no- MT2022112 name - Shubhanshi Bhandari
10. Write a separate program using sigaction system call to catch the following signals.
b. SIGINT

*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void handlerSIGINT(){
    printf("\nKeyboard Interrupt occured!!\n");

    exit(EXIT_SUCCESS);
}

int main(){
    struct sigaction s1;
    s1.sa_handler = handlerSIGINT;
    sigaction(SIGINT, &s1,NULL);
    printf("Press Ctrl+C to catch the SIGINT signal via sigaction..\n");
    while(1);
    return 0;
}
