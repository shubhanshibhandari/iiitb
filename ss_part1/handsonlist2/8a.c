/*reg no- MT2022112 name - Shubhanshi Bhandari
8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV


*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void handler(){
    printf("Segmentation fault occured!!\n");
    exit(EXIT_SUCCESS);
}

int main(){
    signal(SIGSEGV, handler);

   raise(SIGSEGV);

    return 0;
}
