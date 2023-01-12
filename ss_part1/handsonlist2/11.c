/*reg no- MT2022112 name - Shubhanshi Bhandari
11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.

*/

#include <signal.h>
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
void my_handler (int sig); /* function prototype */
int main ( void ) {
struct sigaction my_action;
/* Part I: Catch SIGINT */
my_action.sa_handler = my_handler;
my_action.sa_flags = SA_RESTART;
sigaction (SIGINT, &my_action, NULL);
printf ("Catching SIGINT\n");
sleep(5);
printf (" No SIGINT within 5 seconds\n");
/* Part II: Ignore SIGINT */
my_action.sa_handler = SIG_IGN;
my_action.sa_flags = SA_RESTART;
sigaction (SIGINT, &my_action, NULL);
printf ("Ignoring SIGINT\n");
sleep(5);
printf (" restoring default signal handling\n");
/* Part III: Default action for
SIGINT */
my_action.sa_handler = SIG_DFL;
my_action.sa_flags = SA_RESTART;
sigaction (SIGINT, &my_action, NULL);
while(1);
}
void my_handler (int sig) {
printf ("I got SIGINT, number %d\n", sig);
exit(0);
}
