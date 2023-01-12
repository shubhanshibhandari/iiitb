/*reg no- MT2022112 name - Shubhanshi Bhandari
6. Write a simple program to create three threads.
*/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void run1(){
    printf("This is the first thread!!\n");
}

void run2(){
    printf("This is the second thread!!\n");
}

void run3(){
    printf("This is the third thread!!\n");
}

int main(){

    pthread_t t[3];
    pthread_create(&t[0], NULL, (void *)run1, NULL);
    pthread_create(&t[1], NULL, (void *)run2, NULL);
    pthread_create(&t[2], NULL, (void *)run3, NULL);

    sleep(1);

    printf("Thread1 id : %lu\n",t[0]);
    printf("Thread2 id : %lu\n",t[1]);
    printf("Thread3 id : %lu\n",t[2]);

    return 0;
}
