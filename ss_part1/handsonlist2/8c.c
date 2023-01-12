/*reg no- MT2022112 name - Shubhanshi Bhandari
8. Write a separate program using signal system call to catch the following signals.
c. SIGFPE
*/


#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void handler(){
    printf("Floating-point exception occured!!\n");
    exit(EXIT_SUCCESS);
}

int main(){
    signal(SIGFPE, handler);

    int a = 0;
    float b = 2 % a;

    return 0;
}
