/*reg no- MT2022112 name - Shubhanshi Bhandari
19. Create a FIFO file by
d. mkfifo library function
*/
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>
#include <stdio.h>  


int main(){
char * myfifo = "/tmp/myfifo_mknod";
mknod(myfifo,S_IRUSR|S_IWUSR|S_IFIFO,0);


}

