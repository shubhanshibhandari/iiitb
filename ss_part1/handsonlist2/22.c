/*reg no- MT2022112 name - Shubhanshi Bhandari
22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
       int main(void)
       {   int fd;

           fd_set rfds;
           struct timeval tv;
           int retval;
           // FIFO file path

           char * myfifo = "/tmp/myfifo";
           mkfifo(myfifo, 0666);
    
           fd=open(myfifo,O_NONBLOCK | O_RDONLY);
           /*if (fd == -1)
    {
        perror("Error while opening FIFO file!");
        _exit(0);
    }*/

	   printf("checking if someone writes into fifo next 10 sec\n");
           FD_ZERO(&rfds);
           FD_SET(fd, &rfds);

           /* Wait up to 10 seconds. */

           tv.tv_sec = 10;
           tv.tv_usec = 0;
	   /*use program 20_1.c to write into pipe within 10 sec*/

           retval = select(fd+1, &rfds, NULL, NULL, &tv);
           /* Don't rely on the value of tv now! */

           if (retval == -1)
               perror("select()");
           else if (retval)
               printf("Data is available now.\n");
               /* FD_ISSET(0, &rfds) will be true. */
           else
               printf("No data within 10 seconds.\n");

           exit(EXIT_SUCCESS);
       }
