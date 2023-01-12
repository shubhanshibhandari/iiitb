/*Reg no- MT2022112 name - Shubhanshi Bhandari
28. Write a program to get maximum and minimum real time priority.
*/
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include  <sys/types.h>

int main(){


	printf("Maximum Real Time Priority(FIFO) : %d\n",sched_get_priority_max(SCHED_FIFO));

	printf("Minimum Real Time Priority(FIFO) : %d\n",sched_get_priority_min(SCHED_FIFO));
	printf("Maximum Real Time Priority(RR) : %d\n",sched_get_priority_max(SCHED_RR));

	printf("Minimum Real Time Priority(RR) : %d\n",sched_get_priority_min(SCHED_RR));
	printf("Maximum Real Time Priority : %d\n",sched_get_priority_max(SCHED_OTHER));

	printf("Minimum Real Time Priority : %d\n",sched_get_priority_min(SCHED_OTHER));

	return 0;
}
