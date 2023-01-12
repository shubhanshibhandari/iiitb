/*reg no.-MT2022112 Name- Shubhanshi Bhandari
1. Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void){
mknod("Myfifo", S_IFIFO,0);
perror("return myfifo:");
}



