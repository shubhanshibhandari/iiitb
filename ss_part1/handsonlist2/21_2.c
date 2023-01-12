/*reg no- MT2022112 name - Shubhanshi Bhandari
21. Write two programs so that both can communicate by FIFO -Use two way communications.

*/
// program that reads first

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;
    int nread;
        char * myfifo = "/tmp/myfifo";
	mkfifo(myfifo, 0666);

    char str1[80], str2[80];
    while (1)
    {
         memset(str1,0,80);
        memset(str2,0,80);
	    // First open in read only and read
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1, 80);

        // Print the read string and close
        printf("User1: %s\n", str1);
        close(fd1);

        // Now open in write mode and write
        // string taken from user.
        fd1 = open(myfifo,O_WRONLY);
        nread= read(0,str2,80);
        write(fd1, str2, nread);
        close(fd1);
    }
    return 0;
}
