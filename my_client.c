#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <Winsock2.h> //For Windows Socket API
#include <unistd.h>  //For POSIX operating system APIs (not needed here)
#include <pthread.h> //For multithreading capabilities (not used here)


int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM,0);
    if (sockfd == -1)
    {
        perror("Error creating Socket");
        exit(0);
    }
}