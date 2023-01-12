/*reg no- MT2022112 name - Shubhanshi Bhandari
33. Write a program to communicate between two machines using socket.
*/


#include <sys/types.h>  
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdio.h>      
#include <unistd.h>     
#include<fcntl.h>
#include<sys/stat.h>
#include <arpa/inet.h>
#include<netdb.h>
#include<string.h>
void main()
{
    int sfd;     
    int cstatus;
    struct sockaddr_in address; 
    int x=2;
    char buff[100];
    //struct hostent *ptrh;
    //memset((char*)&address,0,sizeof(address));
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd== -1)
    {
        perror("Error while creating socket!");
        _exit(0);
    }
    printf("Client side socket successfully created!\n");

        
    //memset((char*)&address,0,sizeof(address));
    address.sin_addr.s_addr = inet_addr("172.16.144.70");
    address.sin_family = AF_INET;
    address.sin_port = htons(5500);
    //ptrh=gethostbyname("172.16.144.70");
    //memcpy(&address.sin_addr,ptrh->h_addr,ptrh->h_length);
    cstatus=connect(sfd, (struct sockaddr *)&address, sizeof(address));
    if (cstatus == -1)
    {
        perror("Error while connecting to server!");
        _exit(0);
    }
    printf("Client to server connection successfully established!\n");

    
//while(x--){
    
       write(sfd, "hello from the client\n", 23);
       read(sfd, buff, 100);
//}
       printf("Data from server: %s\n", buff);
      
    

    close(sfd);
}
