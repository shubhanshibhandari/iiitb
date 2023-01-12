/*reg no - MT2022112 name - Shubhanshi Bhandari
16. Write a program to perform mandatory locking.
b. Implement read lock
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h>

int main()
{
	printf("Opening....\n");
	int fd = open("/home/shubhanshibhandari/Desktop/software_system/file1.txt", O_RDWR); 

	struct flock writelock; 
	
	printf("before write Locking....\n" );

	writelock.l_type = F_WRLCK; 
	writelock.l_whence = SEEK_SET; 
	writelock.l_start = 0; 
	writelock.l_len = 0; 
	writelock.l_pid = getpid(); 
	fcntl(fd, F_SETLKW, &writelock); 
        printf("in the critical section..\n");
	printf("Press Enter to Unlock\n");
	getchar(); 
	writelock.l_type = F_UNLCK; 
	fcntl(fd, F_SETLK, &writelock); 
	printf("exictted the critical section...\n");
	printf("Unlocked\n");

 	return 0;
}
