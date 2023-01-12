/*reg no- MT2022112 name - Shubhanshi Bhandari
7. Write a simple program to print the created thread ids.
*/
#include <pthread.h> // Import for `pthread_create`
#include <stdio.h>   // Import for `perror` & `printf`

void sampleFunction()
{
    printf("Running in thread with thread ID: %lu\n", pthread_self());
}

void main()
{
    pthread_t threadID;

    // Create thread
    pthread_create(&threadID, NULL, (void *)sampleFunction, NULL);
    printf("Thread1 id : %lu\n",threadID);
    pthread_exit(NULL);
}
