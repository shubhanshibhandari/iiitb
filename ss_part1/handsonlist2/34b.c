/*reg no- MT2022112 name - Shubhanshi Bhandari
34. Write a program to create a concurrent server.
a. use fork
b. use pthread_create

*/

#include<string.h>
#include <sys/types.h>  
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdio.h>      
#include <unistd.h>     
#include<fcntl.h>
#include<pthread.h>
#include<sys/stat.h>
void func(int *fd)
{
 char buff1[100];
           memset(buff1,0, sizeof(buff1));
	   read(*fd, buff1, 100);
           printf("message from client: %s\n", buff1);
           write(*fd, "ack from server\n", 17);
           close(*fd);
}

void main()
{
    int sfd;     
    int sz,nsd;
    struct sockaddr_in server,client; 

    char buff[100];
    pthread_t threadID;
    
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd== -1)
    {
        perror("Error while creating socket!");
        _exit(0);
    }
    printf("Server side socket successfully created!\n");

        
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(5500);
    bind(sfd,(struct sockaddr *)(&server),sizeof(server));
    //cstatus=connect(sfd, (struct sockaddr *)&address, sizeof(address));
    //if (cstatus == -1)
    //{
      //  perror("Error while connecting to server!");
        //_exit(0);
    //}
    //printf("Client to server connection successfully established!\n");

    listen(sfd,2);
     printf("Now listening for connections on a socket!\n");
    while(1){
    
    sz=sizeof(client);
    nsd=accept(sfd,(struct sockaddr*)(&client),&sz);
    if (pthread_create(&threadID, NULL, (void *)func, &nsd))
                perror("Error while creating thread"); 
  
    }
    
    close(sfd);
    
    }
    
