/*reg no- MT2022112 name - Shubhanshi Bhandari
23. Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
*/

#include<stdio.h>
#include <unistd.h>
int main(){
long PIPE_BUF,OPEN_MAX;
PIPE_BUF = pathconf(".",_PC_PIPE_BUF);
OPEN_MAX = sysconf(_SC_OPEN_MAX);
printf("pipe_buf=%ld\t OPEN_MAX=%ld\n",PIPE_BUF,OPEN_MAX);

}
