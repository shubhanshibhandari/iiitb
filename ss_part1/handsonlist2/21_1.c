/*reg no- MT2022112 name - Shubhanshi Bhandari
21. Write two programs so that both can communicate by FIFO -Use two way communications.

*/
// program that write first
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;

    // FIFO file path
    char * myfifo = "/tmp/myfifo";

    int nread;
    mkfifo(myfifo, 0666);

    char arr1[80], arr2[80];
    while (1)
    {   memset(arr1,0,80);
        memset(arr2,0,80);
        
    
        
        fd = open(myfifo, O_WRONLY);

       nread= read(0,arr2,80);
        write(fd, arr2, nread);
        close(fd);

        
        fd = open(myfifo, O_RDONLY);

        
        read(fd, arr1, sizeof(arr1));

        
        printf("User2: %s\n", arr1);
        close(fd);
    }
    return 0;
}
