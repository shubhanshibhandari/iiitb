/*Reg no - MT2022112 Name - Shubhanshi Bhandari
26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/
#include<unistd.h>
#include<stdio.h>
//#include<>
//#include<>
int main(){
	char *path="test.out";
	char *arg1="hello world";
	int e = execl(path,path,arg1,NULL);
	if(e==-1){
	perror("error....");
	}
	return 0;
}
