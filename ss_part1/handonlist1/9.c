/*reg no - MT2022112 name - Shubhanshi Bhandari
9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include <fcntl.h> 

int main(){
	struct stat stat_file;
	int fd1 = open("file1.txt", O_RDONLY);
	if (fd1 == -1)
	{
		perror("opening file1.txt");
		
		return 0;
	}
	fstat(fd1,&stat_file);
	printf("inode = %lo\n",stat_file.st_ino);
	printf("no. of hrdlink = %lo\n",stat_file.st_nlink);
	printf("uid = %o\n",stat_file.st_uid);
        printf("gid = %o\n",stat_file.st_gid);
	printf("size = %lo\n",stat_file.st_size);
        printf("block size = %lo\n",stat_file.st_blksize);
        printf("no. of block = %lo\n",stat_file.st_blocks);
        printf("last access = %lo\n",stat_file.st_atime);
        printf("last modification = %lo\n",stat_file.st_mtime);
        printf("last change = %lo\n",stat_file.st_ctime);
	return 0;
}
