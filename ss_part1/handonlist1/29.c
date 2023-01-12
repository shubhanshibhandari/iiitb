/*Reg no- MT2022112 name - Shubhanshi Bhandari 

 Write a program to get the scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
*/
#include <sched.h> 
#include <sys/types.h> 
#include <unistd.h>    
#include <stdio.h>     

int main()
{
    int currentPolicy;
    pid_t pid;
    pid = getpid();
    currentPolicy = sched_getscheduler(pid);
    struct sched_param priority;
    
    priority.sched_priority = 10;

    switch (currentPolicy)
    {
    case SCHED_FIFO:
        printf("Current policy is FIFO\n");
        sched_setscheduler(pid, SCHED_RR, &priority);
        currentPolicy = sched_getscheduler(pid);
        if(currentPolicy==SCHED_RR)
        printf("Current policy is Round robin");
        break;
    case SCHED_RR:
        printf("Current policy is RR\n");
        sched_setscheduler(pid, SCHED_FIFO, &priority);
        currentPolicy = sched_getscheduler(pid);
        if (currentPolicy==SCHED_FIFO)
        printf("Current policy is FIFO");
        break;
    case SCHED_OTHER:
        printf("Current policy is OTHER\n");
        sched_setscheduler(pid, SCHED_RR, &priority);
        currentPolicy = sched_getscheduler(pid);
        if (currentPolicy==SCHED_RR)
        printf("Current policy is Round robin");
        break;
    default:
        perror("Error while getting current policy\n");
    }
    return 0;
}


