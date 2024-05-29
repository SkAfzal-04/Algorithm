#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 5
int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}
int printMST(int parent[], int graph[V][V])
{
	printf("Edge \tWeight\n");
	for (int i = 1; i < V; i++)
		printf("%d - %d \t%d \n", parent[i], i,
			graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{

	int parent[V];
	int key[V];
	bool mstSet[V];
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {

		int u = minKey(key, mstSet);
		mstSet[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, graph);
}

int main()
{
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	primMST(graph);

	return 0;
}

// Algorithm
// START

// DEFINE FUNCTION minKey(key[], mstSet[])
//     DECLARE min as integer, min_index as integer
//     SET min to INT_MAX
//     FOR v = 0 to V-1 DO
//         IF mstSet[v] is false AND key[v] < min THEN
//             SET min to key[v]
//             SET min_index to v
//         END IF
//     END FOR
//     RETURN min_index
// END FUNCTION

// DEFINE FUNCTION printMST(parent[], graph[V][V])
//     PRINT "Edge \tWeight"
//     FOR i = 1 to V-1 DO
//         PRINT parent[i] concatenated with " - " concatenated with i concatenated with " \t" concatenated with graph[i][parent[i]]
//     END FOR
// END FUNCTION

// DEFINE FUNCTION primMST(graph[V][V])
//     DECLARE parent[V], key[V] as arrays of integers
//     DECLARE mstSet[V] as array of boolean values
//     FOR i = 0 to V-1 DO
//         SET key[i] to INT_MAX
//         SET mstSet[i] to false
//     END FOR
//     SET key[0] to 0
//     SET parent[0] to -1

//     FOR count = 0 to V-2 DO
//         DECLARE u as integer
//         SET u to minKey(key, mstSet)
//         SET mstSet[u] to true

//         FOR v = 0 to V-1 DO
//             IF graph[u][v] is not equal to 0 AND mstSet[v] is false AND graph[u][v] < key[v] THEN
//                 SET parent[v] to u
//                 SET key[v] to graph[u][v]
//             END IF
//         END FOR
//     END FOR

//     CALL printMST(parent, graph)
// END FUNCTION

// START main function
//     DECLARE graph[V][V] as 2D array of integers
//     ASSIGN values to graph
//     CALL primMST(graph)
// END main function
