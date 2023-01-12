#include<stdio.h>
int main(int argc,char **argv){
printf("arguments execl passed  are :");
for (int i=1;i<argc;i++)
{
	printf("%s\n",argv[i]);
}
}

