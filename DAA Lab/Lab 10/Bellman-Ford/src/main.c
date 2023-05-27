#include <stdio.h>
#include "my_functions.h"

// From a given vertex in a weighted connected graph, Write a program to find shortest paths to other vertices using Bellman-Ford algorithm. Draw simple, connected weighted graph with 10 vertices and 18 edges, such that graph contains minimum weight cycle with at least 4 edges. Show that the Bellman-Ford algorithm find this cycle.
int main()
{
    int size;
    printf("Enter the number of vertices : ");
    scanf("%d", &size);
    int *ptr = (int *)malloc(size * sizeof(int));
    inputArray(ptr, size);  
    printf("The given array is : ");
    printArray(ptr, size);
        
    return 0;
}
