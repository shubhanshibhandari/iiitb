/*reg no- MT2022112 name - Shubahnshi Bhandari
11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
*/

#include <unistd.h>
#include <fcntl.h>
#include<sys/types.h>
#include<stdio.h>
int main(){
	int fd,dup_fd;
	char buf[100];
	char temp;
	int nread;
	fd=open("/home/shubhanshibhandari/Desktop/software_system/file_for_ques11.txt",O_RDWR | O_APPEND);
	dup_fd= fcntl(fd, F_DUPFD ,50);

	printf("first fd is %d and duplicate fd is %d\n",fd,dup_fd);
	printf("enter msg to write using orignal fd\n");
	nread=read(0,buf,sizeof(buf));
	write(fd,buf,nread);
        printf("enter msg to write using duplicate fd\n");
	nread=read(0,buf,sizeof(buf));
        write(dup_fd,buf,nread);
	lseek(fd,0,SEEK_SET);
	printf("\n");
	while(read(fd,&temp,1)>0)
		write(1,&temp,1);

	return 0;
}
