#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <Winsock2.h> //For Windows Socket API
#include <unistd.h>  //For POSIX operating system APIs (not needed here)
#include <pthread.h> //For multithreading capabilities (not used here)


int main()
{
    //Creating Socket File Descriptor
    int socket_fd = socket(AF_INET,SOCK_STREAM,0);
    
    //Checking if the socket is created successfully or not
    if (socket_fd == -1)
    {
        perror("Error Creating Socket");
        exit(0);
    }
    else
    {
        printf("Listening on port...");
    }

    //Defining Server Address Structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET; //Address Family IPv4
    server_addr.sin_port = htons(8080); //Port Number in Network Byte Order
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); //IP Address of the Host

    //Binding the Socket with Address and Port number
    if(bind(socket_fd, (struct  sockaddr*)&server_addr, sizeof(server_addr)) < 0 )
    {
        perror("Error binding address to socket");
        exit(0);
    }

    //Listening to incoming connections
    if(listen(socket_fd, 5) < 0 ) // Here, 5 represents the maximum length for the queue of pending connections.
    {
        perror("Error listening to new connections");
        exit(0);
    }
    else
    {
        printf("Server is listening on port 8080... ");        
    }
    

    return 0;
}
