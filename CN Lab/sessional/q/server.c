
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

void countWords(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    printf("Number of words: %d", count);
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

    char str1[100], str2[100];
    recvfrom(server_socket, &str1, sizeof(str1), 0, (struct sockaddr *)&client_address, &client_len);
    recvfrom(server_socket, &str2, sizeof(str2), 0, (struct sockaddr *)&client_address, &client_len);
    printf("Roll number: %s\n", str1);
    printf("Sentance: %s\n", str2);
    int roll = atoi(str1);
    if (roll % 2 != 0)
    {
        countWords(str2);
    }
    else
    {
        printf("Roll number is even");
    }
    close(server_socket);
    return 0;
}