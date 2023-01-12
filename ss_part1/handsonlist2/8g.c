/*reg no- MT2022112 name - Shubhanshi Bhandari
8. Write a separate program using signal system call to catch the following signals.
g. SIGPROF (use setitimer system call)

*/


#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

void timer_handler (int signum)
{
 static int count = 0;
 printf ("timer expired %d times\n", ++count);
}

int main ()
{
 //struct sigaction sa;
 struct itimerval timer;

 /* Install timer_handler as the signal handler for SIGVTALRM. */
 //memset (&sa, 0, sizeof (sa));
 //sa.sa_handler = &timer_handler;
 //sigaction (SIGALRM, &sa, NULL);

signal(SIGPROF,timer_handler);

 /* Configure the timer to expire after 250 msec... */
 timer.it_value.tv_sec = 1;
 timer.it_value.tv_usec = 0;
 /* ... and every 250 msec after that. */
 timer.it_interval.tv_sec = 10;
 timer.it_interval.tv_usec = 10;
 /* Start a virtual timer. It counts down whenever this process is
   executing. */
 setitimer (ITIMER_PROF, &timer, NULL);

 /* Do busy work. */
 while (1);
}

