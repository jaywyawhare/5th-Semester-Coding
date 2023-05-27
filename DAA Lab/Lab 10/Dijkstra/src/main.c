#include <stdio.h>
#include <limits.h>
#include "my_functions.h"

void relax(int u, int v, int w, int *dist, int *parent)
{
    if (dist[v] > dist[u] + w)
    {
        dist[v] = dist[u] + w;
        parent[v] = u;
    }
}
void printPath(int *parent, int j)
{
    if (parent[j] == -1)
    {
        printf("%d ", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("%d ", j);
}

int main()
{
    // From a given vertex in a weighted connected graph, Write a program to find shortest paths to other vertices using Dijkstra's algorithm. Draw simple, connected weighted graph with 8 vertices and 16 edges, each with unique edge weight. Identify one vertex as a start vertex and obtain shortest path using Dijkstra's algorithm.
    int edges, vertices;
    printf("Enter the number of vertices : ");
    scanf("%d", &vertices);
    printf("Enter the number of edges : ");
    scanf("%d", &edges);
    int *dist = (int *)malloc(vertices * sizeof(int));
    int *parent = (int *)malloc(vertices * sizeof(int));
    int *visited = (int *)malloc(vertices * sizeof(int));
    int *adjacencyMatrix = (int *)malloc(vertices * vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            adjacencyMatrix[i * vertices + j] = INT_MAX;
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = 0;
    }
    int u, v, w;
    for (int i = 0; i < edges; i++)
    {
        printf("Enter the edge (u, v) : ");
        scanf("%d %d", &u, &v);
        printf("Enter the weight of the edge : ");
        scanf("%d", &w);
        adjacencyMatrix[u * vertices + v] = w;
    }
    printf("Enter the source vertex : ");
    scanf("%d", &u);
    dist[u] = 0;
    for (int i = 0; i < vertices; i++)
    {
        int min = INT_MAX;
        int minIndex = -1;
        for (int j = 0; j < vertices; j++)
        {
            if (visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                minIndex = j;
            }
        }
        visited[minIndex] = 1;
        for (int j = 0; j < vertices; j++)
        {
            if (adjacencyMatrix[minIndex * vertices + j] != INT_MAX)
            {
                relax(minIndex, j, adjacencyMatrix[minIndex * vertices + j], dist, parent);
            }
        }
    }
    printf("The shortest path from %d to %d is : ", u, v);
    printPath(parent, v);
    for (int i = 0; i < vertices; i++)
    {
        printf("The shortest path from %d to %d is : ", u, i);
        printPath(parent, i);
    }
    return 0;
}
