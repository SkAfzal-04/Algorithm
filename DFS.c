#include <stdio.h>
#define MAX 100

int visited[MAX] = {0};
int graph[MAX][MAX] = {0};
int n, m;

void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int startVertex;

    printf("Enter the number of vertices and edges in the graph: ");
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || n > MAX || m < 0 || m > (n*(n-1))/2) {
        printf("Invalid input for number of vertices and edges.\n");
        return 1;
    }

    printf("Enter the edges in the format (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2 || u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid input for edge.\n");
            return 1;
        }
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter the starting vertex for DFS traversal: ");
    if (scanf("%d", &startVertex) != 1 || startVertex < 0 || startVertex >= n) {
        printf("Invalid input for starting vertex.\n");
        return 1;
    }

    printf("DFS traversal starting from vertex %d: ", startVertex);
    dfs(startVertex);
    printf("\n");

    return 0;
}


// Algorithm
// START
//   DEFINE MAX as 100
//   INITIALIZE visited[MAX] to 0
//   INITIALIZE graph[MAX][MAX] to 0
//   DECLARE n, m as integer

//   FUNCTION dfs(vertex)
//     SET visited[vertex] to 1
//     PRINT vertex

//     FOR i from 0 to n-1
//       IF graph[vertex][i] is 1 AND visited[i] is 0
//         CALL dfs(i)
//     END FOR
//   END FUNCTION

//   MAIN
//     DECLARE startVertex as integer

//     PRINT "Enter the number of vertices and edges in the graph: "
//     READ n, m
//     IF n <= 0 OR n > MAX OR m < 0 OR m > (n*(n-1))/2
//       PRINT "Invalid input for number of vertices and edges."
//       RETURN 1
//     END IF

//     PRINT "Enter the edges in the format (u v):"
//     FOR i from 0 to m-1
//       DECLARE u, v as integer
//       READ u, v
//       IF u < 0 OR u >= n OR v < 0 OR v >= n
//         PRINT "Invalid input for edge."
//         RETURN 1
//       END IF
//       SET graph[u][v] to 1
//       SET graph[v][u] to 1
//     END FOR

//     PRINT "Enter the starting vertex for DFS traversal: "
//     READ startVertex
//     IF startVertex < 0 OR startVertex >= n
//       PRINT "Invalid input for starting vertex."
//       RETURN 1
//     END IF

//     PRINT "DFS traversal starting from vertex ", startVertex, ": "
//     CALL dfs(startVertex)
//     PRINT newline

//     RETURN 0
//   END MAIN
// END

