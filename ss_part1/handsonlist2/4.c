/*reg no- MT2022112 name - Shubhanshi Bhandari
4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.

*/

#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>

unsigned long long rdtsc(){
     unsigned long long dst;
     __asm__     __volatile__ ("rdtsc":"=A" (dst));
     return dst;  
 }
int main () 
 {
   long long int start, end;
   start = rdtsc();
   int i=100;
   while(i--){
    getppid();
   }
   end = rdtsc();
   printf (" Time taken is : %f nano sec", (end - start)/2.9);   
   return 0;
}
