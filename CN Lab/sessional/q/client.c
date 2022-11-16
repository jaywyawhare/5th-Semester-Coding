// create a udp client that will send 2 strings in which first string will be the roll number and second string will be sentance with non uniform spaces and the server will send back the number of words in the sentance if roll number is odd.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int client_socket;
    client_socket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons(9002);
    client_address.sin_addr.s_addr = INADDR_ANY;

    int server_socket;
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    char str1[100], str2[100];
    printf("Enter roll number: ");
    gets(str1);
    printf("Enter sentance: ");
    // scanf(" %[^\n]s ", str2);
    gets(str2);
    sendto(client_socket, &str1, sizeof(str1), 0, (struct sockaddr *)&server_address, sizeof(server_address));
    sendto(client_socket, &str2, sizeof(str2), 0, (struct sockaddr *)&server_address, sizeof(server_address));
    close(client_socket);
    return 0;
}