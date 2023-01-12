/*reg no - MT2022112 name- Shubhanshi Bhandari
19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
unsigned long long rdtsc() {
	unsigned long long dst;
	__asm__ __volatile__("rdtsc":"=A" (dst));
}
int main(void){
	int i,nano;
	unsigned long long int start,end;
	start= rdtsc();
	for(i=0;i<=10000;i++)
		getpid();
	end=rdtsc();
	nano=(end-start)/2.9;
	printf("The function takes %d nano sec\n",nano);

}

