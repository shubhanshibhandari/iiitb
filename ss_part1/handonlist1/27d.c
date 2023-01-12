/* Reg no. -MT2022112 name- Shubhanshi Bhandari
7. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled
d. execv
e. execvp
*/


#include <unistd.h>
#include <stdio.h>

int main(){

	printf("ls -rl (using execv) \n");
	char *buf[3] = {"ls","-Rl",(char *)0};

	int stat = execv("/bin/ls",buf);
	if(stat==-1)
	perror("");
	
	return 0;
}
