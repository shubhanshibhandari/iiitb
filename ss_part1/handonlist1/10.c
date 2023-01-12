/*reg no-MT2022112 name- Shubhanshi Bhandari
10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd;
	int seek_ptr;
	char buf[40]="100 200 300 400 500";
	fd=open("file_for_ques10.txt",O_RDWR | O_CREAT,0744);
	write(fd,buf,10);
	
	lseek(fd,10,SEEK_CUR);
	write(fd,buf,10);
	seek_ptr=lseek(fd,0,SEEK_CUR);
	printf("%d\n",seek_ptr);
	return lptr;	
}
