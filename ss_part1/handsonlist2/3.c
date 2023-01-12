/*reg no- MT2022112 name - Shubhanshi Bhandari
3. Write a program to set (any one) system resource limit. Use setrlimit system call.
*/

#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>


int main(){
    struct rlimit lim;
    
    getrlimit(RLIMIT_CORE, &lim);
    printf("This  is  the maximum size of a core file (see core(5)) in bytes that the process may dump.\n");
    
    printf("Softlimit : %lu \nMaxlimit : %lu \n", lim.rlim_cur, lim.rlim_max);
    printf("\nSetting core dump\n");

    sleep(2);
    

    lim.rlim_cur = 5;
    lim.rlim_max = 10;
    setrlimit(RLIMIT_CPU, &lim);

    getrlimit(RLIMIT_CPU, &lim);
    printf("\nnew limit\n");
    printf("Softlimit : %lu \nMaxlimit : %lu \n", lim.rlim_cur, lim.rlim_max);

    return 0;
}
