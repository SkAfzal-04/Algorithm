#include <stdio.h>
#include <stdlib.h>

int Bellman_Ford(int G[20][20], int V, int E, int edge[20][2]) {
    int i, u, v, k, distance[20], parent[20], S, flag = 1;

    // Initialize distance and parent arrays
    for(i = 0; i < V; i++) {
        distance[i] = 1000;
        parent[i] = -1;
    }

    printf("Enter source: ");
    scanf("%d", &S);
    distance[S - 1] = 0; // Adjusting for 0-based index

    // Relax edges |V| - 1 times
    for(i = 0; i < V - 1; i++) {
        for(k = 0; k < E; k++) {
            u = edge[k][0];
            v = edge[k][1];
            if(distance[u] + G[u][v] < distance[v]) {
                distance[v] = distance[u] + G[u][v];
                parent[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    for(k = 0; k < E; k++) {
        u = edge[k][0];
        v = edge[k][1];
        if(distance[u] + G[u][v] < distance[v]) {
            flag = 0;
        }
    }

    if(flag) {
        for(i = 0; i < V; i++) {
            printf("Vertex %d -> cost = %d parent = %d\n", i + 1, distance[i], parent[i] + 1);
        }
    }

    return flag;
}

int main() {
    int V, edge[20][2], G[20][20], i, j, k = 0;
    printf("BELLMAN FORD\n");
    printf("Enter no. of vertices: ");
    scanf("%d", &V);
    printf("Enter graph in matrix form:\n");

    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            scanf("%d", &G[i][j]);
            if(G[i][j] != 0) {
                edge[k][0] = i;
                edge[k++][1] = j;
            }
        }
    }

    if(Bellman_Ford(G, V, k, edge)) {
        printf("\nNo negative weight cycle\n");
    } else {
        printf("\nNegative weight cycle exists\n");
    }

    return 0;
}

// Algorithm 
// function Bellman_Ford(G, V, E, edge):
//     initialize distance and parent arrays
//     prompt user for source vertex S
//     set distance[S-1] to 0

//     for i from 0 to V-1:
//         for each edge (u, v):
//             if distance[u] + G[u][v] < distance[v]:
//                 update distance[v] and parent[v]

//     check for negative-weight cycles:
//         for each edge (u, v):
//             if distance[u] + G[u][v] < distance[v]:
//                 set flag to 0

//     if no negative-weight cycles:
//         print distances and parents for all vertices

//     return flag

// function main():
//     prompt user for number of vertices V
//     prompt user for graph matrix G

//     extract edges from G and store in edge array

//     if Bellman_Ford(G, V, E, edge) returns 1:
//         print "No negative weight cycle"
//     else:
//         print "Negative weight cycle exists"
