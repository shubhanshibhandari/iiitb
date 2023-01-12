/*reg no- MT2022112 name - Shubhanshi Bhandari

2. Write a program to print the system resource limits. Use getrlimit system call.
*/


#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>


int main(){

    struct rlimit lim;

    getrlimit(RLIMIT_AS, &lim);

    printf("\n\nVirtual Memory Limits in bytes.\n");
    printf("Softlimit : %lu \nMaxlimit : %lu \n", lim.rlim_cur, lim.rlim_max);

    getrlimit(RLIMIT_CPU, &lim);

    printf("\n\nAmount of CPU time process can consume in seconds.\n");
    printf("Softlimit : %lu \nMaxlimit : %lu \n", lim.rlim_cur, lim.rlim_max);

    getrlimit(RLIMIT_DATA, &lim);

    printf("\n\nMax size of the process's segment in bytes.\n");
    printf("Softlimit : %lu \nMaxlimit : %lu \n", lim.rlim_cur, lim.rlim_max);

    return 0;
}
