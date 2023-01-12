/*Reg no-MT2022112 name- Shubhanshi Bhandari
13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
*/
   
       #include <stdio.h>
       #include <stdlib.h>
       #include <sys/time.h>
       #include <sys/types.h>
       #include <unistd.h>

       int
       main(void)
       {
           fd_set rfds;
           struct timeval tv;
           int retval;

           /* Watch stdin (fd 0) to see when it has input. */

           FD_ZERO(&rfds);
           FD_SET(0, &rfds);

           /* Wait up to five seconds. */

           tv.tv_sec = 10;
           tv.tv_usec = 0;
           //write(1,"hi",2);
           retval = select(1, &rfds,NULL, NULL, &tv);
           /* Don't rely on the value of tv now! */
          // write(1,"hi",2);
           if (retval == -1)
               perror("select()");
           else if (retval)
               printf("Data is available now.\n");
               /* FD_ISSET(0, &rfds) will be true. */
           else
               printf("No data within ten  seconds.\n");

           exit(EXIT_SUCCESS);
       }


