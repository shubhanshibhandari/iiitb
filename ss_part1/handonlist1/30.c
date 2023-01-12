#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<time.h>
#include<string.h>


int main(int argc, char const *argv[]){

	if(!fork()){
		setsid();
		chdir("/");
		umask(0);
		
		/*time_t rawtime;
                 struct tm * timeinfo;
                 ctime( &rawtime );
                 timeinfo = localtime( &rawtime );
		while(1){
			
      if(timeinfo->tm_hour==9 && timeinfo->tm_min==0 && timeinfo->tm_sec==0){
                         
			//printf("PID of Daemon process : %d\n",getpid());
		}		
	}
	}*/
	printf("%d",getpid());
	//close(STDIN_FILENO);
        //close(STDOUT_FILENO);
        //close(STDERR_FILENO);
        //printf("%d",getpid());
        int fd=open("/home/kakshi/Desktop/log.txt",O_CREAT| O_RDWR,0777);
	while(1){
	time_t t = time(NULL);
         char *arr=ctime(&t);
	write(fd,arr,strlen(arr));
	sleep(60);
	//printf("PID of Daemon process : %d\n",getpid());
	
	}
	}
	
	else{
		exit(0);
		
	}
	return 0;
}
