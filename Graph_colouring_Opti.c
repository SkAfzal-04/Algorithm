#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];
int numNodes;

bool isSafe(int node, int color) {
    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] && color == colors[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int node, int numColors) {
    if (node == numNodes) {
        return true;
    }
    
    for (int color = 1; color <= numColors; color++) {
        if (isSafe(node, color)) {
            colors[node] = color;
            if (graphColoringUtil(node + 1, numColors)) {
                return true;
            }
            colors[node] = 0;
        }
    }
    
    return false;
}

void graphColoring(int numColors) {
    for (int i = 0; i < numNodes; i++) {
        colors[i] = 0;
    }
    
    if (graphColoringUtil(0, numColors)) {
        printf("Graph can be colored with %d colors.\n", numColors);
        printf("Node colors:\n");
        for (int i = 0; i < numNodes; i++) {
            printf("Node %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("Graph cannot be colored with %d colors.\n", numColors);
    }
}

int main() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);
    
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    int numColors;
    printf("Enter the number of colors available: ");
    scanf("%d", &numColors);
    
    graphColoring(numColors);
    
    return 0;
}

// Algorithm
// START

// CONSTANT MAX_NODES = 100

// DECLARE graph as 2D array of size MAX_NODES x MAX_NODES
// DECLARE colors as array of size MAX_NODES
// DECLARE numNodes

// FUNCTION isSafe(node, color)
//     FOR i FROM 0 TO numNodes-1
//         IF graph[node][i] AND color == colors[i]
//             RETURN false
//     RETURN true
// END FUNCTION

// FUNCTION graphColoringUtil(node, numColors)
//     IF node == numNodes
//         RETURN true

//     FOR color FROM 1 TO numColors
//         IF isSafe(node, color)
//             colors[node] = color
//             IF graphColoringUtil(node + 1, numColors)
//                 RETURN true
//             colors[node] = 0

//     RETURN false
// END FUNCTION

// PROCEDURE graphColoring(numColors)
//     FOR i FROM 0 TO numNodes-1
//         colors[i] = 0

//     IF graphColoringUtil(0, numColors)
//         PRINT "Graph can be colored with" numColors "colors."
//         PRINT "Node colors:"
//         FOR i FROM 0 TO numNodes-1
//             PRINT "Node" i ": Color" colors[i]
//     ELSE
//         PRINT "Graph cannot be colored with" numColors "colors."
// END PROCEDURE

// MAIN
//     PRINT "Enter the number of nodes in the graph: "
//     READ numNodes

//     PRINT "Enter the adjacency matrix for the graph:"
//     FOR i FROM 0 TO numNodes-1
//         FOR j FROM 0 TO numNodes-1
//             READ graph[i][j]

//     PRINT "Enter the number of colors available: "
//     READ numColors

//     CALL graphColoring(numColors)

// END MAIN

// STOP
