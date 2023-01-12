/*Reg no.- MT2022112 name- Shubhanshi Bhandari
7. Write a program to copy file1 into file2 ($cp file1 file2).
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 

void main()
{
	char buf;
	int fd1, fd2;

	fd1 = open("file1.txt", O_RDONLY);

	if (fd1 == -1)
	{
		perror("opening file1.txt");
		
		return;
	}

	fd2 = open("file2.txt", O_WRONLY | O_CREAT,0744);
        char *buff1="this is file2. ";
        //printf("%s",buff1);
	write(fd2, buff1, 15);
	while(read(fd1, &buf, 1))
	{
		write(fd2, &buf, 1);
	}


}
