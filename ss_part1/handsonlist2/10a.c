/*reg no- MT2022112 name - Shubhanshi Bhandari
10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV

*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void handlerSIGSEGV(){
    printf("Segmentation fault occured!!\n");
    exit(EXIT_SUCCESS);
}

int main(){
    
    struct sigaction s1;
    s1.sa_handler = handlerSIGSEGV;
    sigaction(SIGSEGV, &s1,NULL);
    //int a;
    //scanf("%d", a);
    char *str;
    str = "sita rama";    
   *(str + 1) = 'm';
    return 0;
}
