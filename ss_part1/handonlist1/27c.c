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

	printf("ls -rl (using execle) \n");
	int stat = execle("/bin/ls","ls","-Rl",(char *)0,(char *)0);
	if(stat==-1)
	perror("");
	
	return 0;
}
