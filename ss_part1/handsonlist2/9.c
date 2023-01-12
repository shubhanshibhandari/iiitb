/*reg no- MT2022112 name - Shubhanshi Bhandari
9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.

*/
#include <signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void my_handler (int sig); /* function prototype */
int main ( void ) {
/* Part I: Catch SIGINT */
signal (SIGINT, my_handler);
printf ("Catching SIGINT\n");
sleep(5);
printf (" No SIGINT within 5 seconds\n");
/* Part II: Ignore SIGINT */
signal (SIGINT, SIG_IGN);
printf ("Ignoring SIGINT\n");
sleep(5);
printf ("No SIGINT within 5 seconds\n");
/* Part III: Default action for SIGINT */
signal (SIGINT, SIG_DFL);
printf ("Default action for SIGINT\n");
while(1);

return 0;
}
/* User-defined signal handler function */
void my_handler (int sig) {
printf ("I got SIGINT, number %d\n", sig);
exit(0);
}
