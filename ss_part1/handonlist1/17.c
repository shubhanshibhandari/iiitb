/*reg no-MT2022112 name - Shubhanshi Bhandari
16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
*/
// use createdb.c to create the database 



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h>

struct
{
	int ticket; 
}reg;

int main(int argc, char const *argv[])
{
	printf("Opening....\n");
	int fd = open("db",O_RDWR); 
/*	reg.ticket = 1; 
	write(fd, &reg, sizeof(reg));*/ 

	struct flock lock; 
	
	printf("Register Locking....\n" );
	lock.l_type = F_WRLCK; 
	lock.l_whence = SEEK_SET; 
	lock.l_start = 0; 
	lock.l_len = 0; 
	lock.l_pid = getpid(); 

	read(fd, &reg, sizeof(reg)); 

	fcntl(fd, F_SETLKW, &lock);	 
	reg.ticket++ ; 
	printf("New Ticket Number : %d\n", reg.ticket);
	lseek(fd, 0, SEEK_SET); 
	write(fd, &reg, sizeof(reg));  

	printf("Press Enter to Unlock\n");
	getchar(); 
	lock.l_type = F_UNLCK; 
	fcntl(fd, F_SETLK, &lock); 
	printf("Unlocked\n");

 	return 0;
}
