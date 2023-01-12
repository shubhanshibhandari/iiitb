/*reg no -MT2022112 name - Shubhanshi Bhandari
8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 

int main(void)
{       char buf[10000];

	int fd1;
        int n=0;;
	fd1 = open("file1.txt", O_RDONLY);
	if (fd1 == -1)
	{
		perror("opening file1.txt");
		
		return 0;
	}

	while(read(fd1,&buf[n],1)>0){
		if(buf[n]=='\n'){
		
		write(1,&buf,n+1);
		n=0;
		getchar();
		}
		else 
		n++;
	}
	

	return 0;

}
