/*reg no- MT2022112 name - Shubhanshi Bhandari
10. Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE

*/


#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void handlerSIGFPE(){
    printf("Floating-point exception occured!!\n");
    exit(EXIT_SUCCESS);
}

int main(){
    struct sigaction s1;
    s1.sa_handler = handlerSIGFPE;
    sigaction(SIGFPE, &s1,NULL);
    int a = 0;
    float b = 2 % a;

    return 0;
}
