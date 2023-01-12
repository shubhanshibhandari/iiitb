/*REg no. - MT2022112 Name - Shubhanshi Bhandari
5. Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
*/
#include<stdio.h>
void main(){
	int fd1 = creat("source1",0744);
	int fd2 = creat("source2",0744);
        int fd3 = creat("source3",0744);
	int fd4 = creat("source4",0744);
	int fd5 = creat("source5",0744);
	getchar();

}
