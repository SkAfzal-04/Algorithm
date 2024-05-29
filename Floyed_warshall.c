#include <stdio.h>
#include <limits.h>
#define V 4
void printSolution(int dist[][V]) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V]) {
    int dist[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) {

        for (int i = 0; i < V; i++) {

            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}

int main() {
    int graph[V][V] = {{0, 5, INT_MAX, 10},
                       {INT_MAX, 0, 3, INT_MAX},
                       {INT_MAX, INT_MAX, 0, 1},
                       {INT_MAX, INT_MAX, INT_MAX, 0}};
    floydWarshall(graph);
    return 0;
}

// Algorithm
// START

// DEFINE V as 4
// DEFINE INF as a large value (e.g., INT_MAX)

// FUNCTION printSolution(dist)
//     PRINT "The following matrix shows the shortest distances between every pair of vertices:"
//     FOR i FROM 0 TO V-1
//         FOR j FROM 0 TO V-1
//             IF dist[i][j] == INF
//                 PRINT "INF"
//             ELSE
//                 PRINT dist[i][j]
//         PRINT new line
// END FUNCTION

// FUNCTION floydWarshall(graph)
//     DECLARE dist as 2D array of size VxV
//     FOR i FROM 0 TO V-1
//         FOR j FROM 0 TO V-1
//             dist[i][j] = graph[i][j]

//     FOR k FROM 0 TO V-1
//         FOR i FROM 0 TO V-1
//             FOR j FROM 0 TO V-1
//                 IF dist[i][k] != INF AND dist[k][j] != INF AND dist[i][k] + dist[k][j] < dist[i][j]
//                     dist[i][j] = dist[i][k] + dist[k][j]

//     CALL printSolution(dist)
// END FUNCTION

// MAIN
//     DECLARE graph as 2D array of size VxV and initialize with given values
//         graph = {{0, 5, INF, 10},
//                  {INF, 0, 3, INF},
//                  {INF, INF, 0, 1},
//                  {INF, INF, INF, 0}}
//     CALL floydWarshall(graph)
// END MAIN

// STOP
