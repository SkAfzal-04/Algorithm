#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int V) {
    printf("Vertex \t\t Distance from Source\n");
    int tc = 0;
    for (int i = 0; i < V; i++) {
        tc += dist[i];
        printf("%d \t\t\t\t %d\n", i, dist[i]);
    }
    printf("\nTotal Distance: %d\n", tc);
}

void dijkstra(int **graph, int src, int V) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);

        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }

    printf("Enter the adjacency matrix for the graph (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source, V);

    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

// Algorithm
// START

// FUNCTION minDistance(dist, sptSet, V)
//     min = INT_MAX
//     min_index = -1
//     FOR v FROM 0 TO V-1
//         IF sptSet[v] IS FALSE AND dist[v] <= min
//             min = dist[v]
//             min_index = v
//     RETURN min_index
// END FUNCTION

// FUNCTION printSolution(dist, V)
//     PRINT "Vertex \t Distance from Source"
//     tc = 0
//     FOR i FROM 0 TO V-1
//         tc = tc + dist[i]
//         PRINT i, "\t", dist[i]
//     PRINT "Total Distance:", tc
// END FUNCTION

// FUNCTION dijkstra(graph, src, V)
//     DECLARE dist[V]
//     DECLARE sptSet[V]
//     FOR i FROM 0 TO V-1
//         dist[i] = INT_MAX
//         sptSet[i] = FALSE
//     dist[src] = 0

//     FOR count FROM 0 TO V-2
//         u = minDistance(dist, sptSet, V)
//         sptSet[u] = TRUE
//         FOR v FROM 0 TO V-1
//             IF NOT sptSet[v] AND graph[u][v] AND dist[u] != INT_MAX AND dist[u] + graph[u][v] < dist[v]
//                 dist[v] = dist[u] + graph[u][v]
//     CALL printSolution(dist, V)
// END FUNCTION

// MAIN
//     DECLARE V as integer
//     PRINT "Enter the number of vertices: "
//     READ V

//     DECLARE graph as 2D array of integers [V][V]
//     ALLOCATE memory for graph[V][V]

//     PRINT "Enter the adjacency matrix for the graph (V x V):"
//     FOR i FROM 0 TO V-1
//         FOR j FROM 0 TO V-1
//             READ graph[i][j]

//     DECLARE source as integer
//     PRINT "Enter the source vertex: "
//     READ source

//     CALL dijkstra(graph, source, V)

//     DEALLOCATE memory for graph
// END MAIN

// STOP
