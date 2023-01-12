/*reg no -MT2022112 name - Shubhanshi Bhandari
22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
*/


#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
	char buff[100];
	char buff1[]="writing into file using child";
	char buff2[]="writing into file using parent:";
	int fd= open("fileforques22.txt",O_RDWR| O_CREAT |O_APPEND,0744);
       if(fd==-1){
       return 0;
       }
       	if (fork() == 0)
	{
		write(fd,buff1,sizeof(buff1));
		//int nread=read(0,buff,sizeof(buff));
		//write(fd,buff,nread);
      }
	else{
	  write(fd,buff2,sizeof(buff2));
                //int nread=read(0,buff,sizeof(buff));
                //write(fd,buff,nread);
	

	}
}

