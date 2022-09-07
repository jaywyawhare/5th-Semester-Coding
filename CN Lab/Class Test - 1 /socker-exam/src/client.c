// create a udp client that will send 5 numbers to the server and receive the sorted array from the server by using bubbleSort() from my_functions.h

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

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    sendto(client_socket, &arr, sizeof(arr), 0, (struct sockaddr *)&server_address, sizeof(server_address));
    recvfrom(client_socket, &arr, sizeof(arr), 0, NULL, NULL);
    printf("The sorted array is: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    close(client_socket);
    return 0;
}