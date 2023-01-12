/*reg no- MT2022112 name - Shubhanshi Bhandari
8. Write a separate program using signal system call to catch the following signals.

b. SIGINT


*/


#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void handler(){
    printf("keyboard interuppt occured\n");
    exit(EXIT_SUCCESS);
}

int main(){
    signal(SIGINT, handler);
    printf("Press Ctrl+C to catch the SIGINT signal..\n");
    while(1);
    return 0;

}
