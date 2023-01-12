/*Reg no- MT2022112 name - Shubhanshi bhandari 
16. Write a program to perform mandatory locking.
a. Implement write lock
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h>

int main()
{
	printf("Opening....\n");
	int fd = open("file1.txt", O_RDWR); 

	struct flock readlock; 
	
	printf( "before Read Locking....\n" );
	readlock.l_type = F_RDLCK; 
	readlock.l_whence = SEEK_SET; 
	readlock.l_start = 0; 
	readlock.l_len = 0; 
	readlock.l_pid = getpid(); 
	fcntl(fd, F_SETLKW, &readlock); 
        printf("In critical section...\n");
	printf("Press Enter to Unlock\n");
	getchar(); 
	readlock.l_type = F_UNLCK; 
	fcntl(fd, F_SETLK, &readlock); 

	printf("Unlocked\n");

 	return 0;
}
