/*Reg no.- MT2022112 Name - shubhanshi bhandari

18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>




int main(int argc,char **argv,char **envi){
struct {
int ticket_no;
} db;
int n;
int fd=open("record.txt",O_RDWR,0744);
read(fd,&db,sizeof(db));
printf("\nSelect the train number (1,2,3): \n");
scanf("%d",&n);

struct flock lock;
lock.l_type=F_RDLCK;
lock.l_whence=SEEK_SET;
lock.l_start=(n-1)*sizeof(db);
lock.l_len=sizeof(db);
lock.l_pid=getpid();
printf("Before entering critical section");
lseek(fd,(n-1)*sizeof(db),SEEK_SET);
//read(fd,&db,sizeof(db));
fcntl(fd,F_SETLKW,&lock);
printf("\nThe Read lock has been set.");
//db.ticket_no++;
//lseek(fd,-1*sizeof(db),SEEK_CUR);// GO back from current position 
read(fd,&db,sizeof(db));// update db with new ticket number 
printf("\nCurrent ticket number is: %d",db.ticket_no);
printf("\nInside critical section.\nPress Enter to unlock");
getchar();
getchar();
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLKW,&lock);
printf("Unlocked!!\n");
return 0;
}
