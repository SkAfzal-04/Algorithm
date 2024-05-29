#include<stdio.h>
#define V 4
#define INT_MAX 999
int parent[V];
int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

void kruskalMST(int cost[][V])
{
	int mincost = 0;

	for (int i = 0; i < V; i++)
		parent[i] = i;

	int edge_count = 0;
	while (edge_count < V - 1) {
		int min = 999, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (find(i) != find(j) && cost[i][j] < min) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
		printf("Edge %d:(%d, %d) cost:%d \n",edge_count++, a, b, min);
		mincost += min;
	}
	printf("\n Minimum cost= %d \n", mincost);
}

int main()
{
int cost[V][V];

    printf("Enter the cost matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }

	kruskalMST(cost);

	return 0;
}

// Algorithm
// START

// DECLARE parent array of size V
// DECLARE mincost as integer
// DECLARE edge_count as integer

// FOR i = 0 TO V-1 DO
//     SET parent[i] = i
// END FOR

// SET edge_count = 0

// WHILE edge_count < V - 1 DO
//     DECLARE min as integer, a as integer, b as integer
//     SET min = 999, a = -1, b = -1

//     FOR i = 0 TO V-1 DO
//         FOR j = 0 TO V-1 DO
//             IF find(i) != find(j) AND cost[i][j] < min THEN
//                 SET min = cost[i][j]
//                 SET a = i
//                 SET b = j
//             END IF
//         END FOR
//     END FOR

//     CALL union1(a, b)
//     PRINT "Edge " edge_count ":(" a ", " b ") cost:" min
//     INCREMENT edge_count
//     SET mincost = mincost + min
// END WHILE

// PRINT "Minimum cost = " mincost

// STOP

