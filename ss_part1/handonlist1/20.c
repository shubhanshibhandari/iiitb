/*reg no - MT2022112 name - Shubhanshi bhandari
Find out the priority of your running program. Modify the priority with nice command.
*/

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int p =  getpriority(PRIO_PROCESS, 0); 
	printf("Priority of process : %d\n", p);
	nice(10); 	
	printf("New priority of process : %d\n", getpriority(PRIO_PROCESS, 0) );
	return 0;
}
;
