  /*reg no- MT2022112 name - Shubhanshi Bhandari    
      16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
      */
      #include <sys/wait.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>
       #include <string.h>

       int main()
       {
           int fd1[2];

           int fd2[2];
           char buff[80],buff1[80];
	  pid_t cpid;
	  //cpid=fork();
	  while(1){
           pipe(fd1);
	   pipe(fd2);
            
           if(!fork())
	   //if(!cpid)
	   {
		   // buff1[0] = '\0';
		  // sleep(50);
		   close(fd1[0]);
		   printf("Enter message to parent:");
		   scanf(" %[^\n]",buff);
		   write(fd1[1],buff,sizeof(buff));
		   close(fd2[1]);
		   //sleep(20);
		   read(fd2[0],buff1,sizeof(buff1));
		   printf("message from parent:%s\n",buff1);
		   }

  	 else {   // buff2[0]='\0';
	           close(fd1[1]);
                  // sleep(20);
		   read(fd1[0],buff,sizeof(buff));
                   printf("message from child:%s\n",buff);
		   close(fd2[0]);
		   printf("Enter message to child:");
                   scanf(" %[^\n]",buff1);
                   write(fd2[1],buff1,sizeof(buff1));
                   }
	 }
      // }
}


