// create a udp server program that will take 5 numbers from the client and send back the sorted array to the client by using bubbleSort() from my_functions.h

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
// #include "my_functions.h"

void bubbleSort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int server_socket;
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    int client_socket;
    struct sockaddr_in client_address;
    socklen_t client_len;
    client_len = sizeof(client_address);

    int arr[5];
    recvfrom(server_socket, &arr, sizeof(arr), 0, (struct sockaddr *)&client_address, &client_len);
    bubbleSort(arr, 5);
    sendto(server_socket, &arr, sizeof(arr), 0, (struct sockaddr *)&client_address, client_len);

    close(server_socket);
    return 0;
}