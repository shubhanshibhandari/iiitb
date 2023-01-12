/*reg no- MT2022112 name - Shubhanshi Bhandari
Write two programs so that both can communicate by FIFO -Use one way communication.
this is the write end of the question 
*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    int nread;
    // FIFO file path
    char * myfifo = "/tmp/myfifo";

    mkfifo(myfifo, 0666);
   char arr2[80];
    while (1)
    {    //char arr2[80];
        memset(arr2,0,sizeof(arr2));
        fd = open(myfifo, O_WRONLY);
        nread=read(1,arr2,sizeof(arr2));

        write(fd, arr2,nread);
        close(fd);

    }
    return 0;
}
