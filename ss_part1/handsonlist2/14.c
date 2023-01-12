/*reg no- MT2022112 name - Shubhanshi Bhandari

14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int fd[2];
        char buf[80];
        pipe(fd);
        write(fd[1],"Hello World..\n",16);
        read(fd[0],buf,16);
        printf("%s\n",buf);
}	
