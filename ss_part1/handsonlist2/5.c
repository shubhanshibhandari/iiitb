/*reg no- MT2022112 name - Shubhanshi Bhandari
5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.

*/

#include<unistd.h>
#include<stdio.h>

int main(){

    printf("\nMaximum length of the arguments to the exec family of functions\n");
    printf("%ld\n",sysconf(_SC_ARG_MAX));

    printf("\nMaximum number of simultaneous process per user id\n");
    printf("%ld\n",sysconf(_SC_CHILD_MAX));

    printf("\nNumber of clock ticks (jiffy) per second\n");
    printf("%ld\n",sysconf(_SC_CLK_TCK));

    printf("\nMaximum number of open files\n");
    printf("%ld\n",sysconf(_SC_OPEN_MAX));

    printf("\nSize of a page\n");
    printf("%ld\n",sysconf(_SC_PAGE_SIZE));

    printf("\nTotal number of pages in the physical memory\n");
    printf("%ld\n",sysconf(_SC_PHYS_PAGES));

    printf("\nNumber of currently available pages in the physical memory\n");
    printf("%ld\n",sysconf(_SC_AVPHYS_PAGES));


    return 0;
}
