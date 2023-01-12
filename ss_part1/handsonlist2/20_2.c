/*reg no- MT2022112 name - Shubhanshi Bhandari
Write two programs so that both can communicate by FIFO -Use one way communication.
this is the read end of the question 
*/


#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;

    // FIFO file path
    char * myfifo = "/tmp/myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    //mkfifo(myfifo, 0666);
    //fd1 = open(myfifo,O_RDONLY);

   char str1[80];
    while (1)
    {
       //char str1[80];
      // First open in read only and read
      // char str1[80];
         memset(str1,0,sizeof(str1));
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1, sizeof(str1));
        printf("User1: %s\n", str1);
        close(fd1);

    }
    return 0;
}
