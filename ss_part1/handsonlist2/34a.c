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
#include<sys/stat.h>
void main()
{
    int sfd;     
    int sz,nsd;
    struct sockaddr_in server,client; 

    char buff[100];

    
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
    bind(sfd,(void *)(&server),sizeof(server));
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
    nsd=accept(sfd,(void*)(&client),&sz);
    
  // while(1)
   //{     
   if(fork()==0){
	   //close(sfd);
	   memset(buff,0, sizeof(buff));
	   read(nsd, buff, 100);
           printf("message from client: %s\n", buff);
           write(nsd, "ack from server\n", 17);
           //printf("press enter to terminate the connection");
           //getchar();
    }
    else{
    close(nsd);
    }
    }
    }
