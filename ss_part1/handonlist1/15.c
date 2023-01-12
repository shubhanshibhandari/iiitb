/*reg no - MT2022112 name- Shubhanshi Bhandari 
 15. Write a program to display the environmental variable of the user (use environ).
*/

#include <stdio.h>
#include<unistd.h> 
#include<stdlib.h> 

int main(int argc, char const *argv[])
{
	int i=0;
	extern char **environ; 

	while (environ[i]!=NULL){
	//printf("%c",*environ[i]);
	if(environ[i][0]=='U' && environ[i][4]=='='){
	printf("%s",environ[i]);
	break;
	}
        i++;
	}

	return 0;
}
