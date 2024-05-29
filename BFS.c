#include <stdio.h>  
#include <stdlib.h>    
struct node {  
    int vertex;  
    struct node* next;  
};  
  
struct adj_list {  
    struct node* head;  
};  

struct graph {  
    int num_vertices;  
    struct adj_list* adj_lists;   
    int* visited;  
};  
   
struct node* new_node(int vertex) {  
    struct node* new_node = (struct node*)malloc(sizeof(struct node));  
new_node->vertex = vertex;  
new_node->next = NULL;  
    return new_node;  
}   
struct graph* create_graph(int n) {  
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));  
    graph->num_vertices = n;  
    graph->adj_lists = (struct adj_list*)malloc(n * sizeof(struct adj_list));  
    graph->visited = (int*)malloc(n * sizeof(int));  
  
    int i;  
    for (i = 0; i< n; i++) {  
        graph->adj_lists[i].head = NULL;  
        graph->visited[i] = 0;  
    }  
  
    return graph;  
}  
   
void add_edge(struct graph* graph, int src, int dest) {  
    struct node* new_node1 = new_node(dest);  
    new_node1->next = graph->adj_lists[src].head;  
    graph->adj_lists[src].head = new_node1;   
    struct node* new_node2 = new_node(src);  
    new_node2->next = graph->adj_lists[dest].head;  
    graph->adj_lists[dest].head = new_node2;  
}  
    
void bfs(struct graph* graph, int v) {  
    int queue[1000];  
    int front = -1;  
    int rear = -1;  
  
    graph->visited[v] = 1;  
    queue[++rear] = v;  
  
 
    while (front != rear) {  
          
        int current_vertex = queue[++front];  
printf("%d ", current_vertex);  
  
        
        struct node* temp = graph->adj_lists[current_vertex].head;  
        while (temp != NULL) {  
            int adj_vertex = temp->vertex;  
  
          
            if (graph->visited[adj_vertex] == 0) {  
                graph->visited[adj_vertex] = 1;  
                queue[++rear] = adj_vertex;  
            }  
  
            temp = temp->next;  
        }  
    }  
}  
  
int main() {  
   
    struct graph* graph = create_graph(6);  
   
add_edge(graph, 0, 1);  
add_edge(graph, 0, 2);  
add_edge(graph, 1, 3);  
add_edge(graph, 1, 4);  
add_edge(graph, 2, 4);  
add_edge(graph, 3, 4);  
add_edge(graph, 3, 5);  
add_edge(graph, 4, 5);  
       
printf("BFS traversal starting from vertex 0: ");  
bfs(graph, 0);  
  
    return 0;  
}

// Algorithm
// function new_node(vertex):
//     allocate memory for new node
//     set new_node.vertex to vertex
//     set new_node.next to NULL
//     return new_node

// function create_graph(num_vertices):
//     allocate memory for graph
//     set graph.num_vertices to num_vertices
//     allocate memory for graph.adj_lists
//     allocate memory for graph.visited
//     initialize all adj_lists heads to NULL and visited to 0
//     return graph

// function add_edge(graph, src, dest):
//     create new_node1 for dest
//     add new_node1 to the adjacency list of src
//     create new_node2 for src
//     add new_node2 to the adjacency list of dest

// function bfs(graph, start_vertex):
//     initialize queue
//     mark start_vertex as visited
//     enqueue start_vertex

//     while queue is not empty:
//         dequeue current_vertex
//         print current_vertex

//         for each adj_vertex of current_vertex:
//             if adj_vertex is not visited:
//                 mark adj_vertex as visited
//                 enqueue adj_vertex

// function main:
//     create graph with 6 vertices
//     add edges to the graph
//     print "BFS traversal starting from vertex 0: "
//     bfs(graph, 0)

// main
