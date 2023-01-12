/*reg no - MT2022112 name - Shubhanshi Bhandari
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
int fd;
struct {
int train_number;
int ticket_count;
} db[3];

for(int i=0;i<3;i++)
{
db[i].train_number=i+1;
db[i].ticket_count=1;
}


fd=creat("record.txt",0744);
write(fd,db,sizeof(db));
close(fd);
return 0;
}
