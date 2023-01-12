/* name - shubhanshi bhandari , reg no- MT2022112
25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
 */
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
  int i,j,k;
  if(!(i = fork()))
     sleep(1);
  else
     if(!(j=fork()))
       sleep(3);
      else
          if(!(j=fork()))
             sleep(3);
          else
          	if(!(k=fork()))
          		sleep(10);
          	else
          	    waitpid(k,NULL,0);
}
      
  
  
  
  
  
  
  
  /*pid_t cpid,w;
  int wstatus;
  if (fork() == 0){
        printf(" first child pid :%d\n",getpid());
         exit(0);
         
                
  }
  
    // parent process because return value non-zero.
    else{
         printf("process id of  Parent:%d\n",getpid());
         cpid=fork();
         if (cpid==0){
         printf(" second child pid :%d\n",getpid());
         sleep(5);
         exit(0);
         }
         else{
                 printf("waiting for second child\n");
		 do {
                   w = waitpid(cpid, &wstatus, WUNTRACED | WCONTINUED);
                   if (w == -1) {
                       perror("waitpid");
                       exit(EXIT_FAILURE);
                   }

                   if (WIFEXITED(wstatus)) {
                       printf("exited, status=%d\n", WEXITSTATUS(wstatus));
                   } else if (WIFSIGNALED(wstatus)) {
                       printf("killed by signal %d\n", WTERMSIG(wstatus));
                   } else if (WIFSTOPPED(wstatus)) {
                       printf("stopped by signal %d\n", WSTOPSIG(wstatus));
                   } else if (WIFCONTINUED(wstatus)) {
                       printf("continued\n");
                   }
               } while (!WIFEXITED(wstatus));
               
               
               
          
           
          if (fork() == 0){
        printf(" third child pid :%d\n",getpid());
         exit(0);
         }
         else{
         printf("Created all three child\n");
          exit(EXIT_SUCCESS);
    }
}
}*/

