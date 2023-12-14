//This program is created by Rachit Bhat PRN 22610007 batch S1 and the program is traversal in graph

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node* adjLists[MAX_VERTICES];
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    for (int i = 0; i < V; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void DFS(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* adjList = graph->adjLists[vertex];
    while (adjList) {
        int dest = adjList->data;
        if (!visited[dest]) {
            DFS(graph, dest, visited);
        }
        adjList = adjList->next;
    }
}

void BFS(struct Graph* graph, int start) {
    bool visited[MAX_VERTICES] = { false };
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    visited[start] = true;
    queue[++rear] = start;

    printf("Breadth-First Search starting from vertex %d: ", start);

    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* adjList = graph->adjLists[current];
        while (adjList) {
            int dest = adjList->data;
            if (!visited[dest]) {
                visited[dest] = true;
                queue[++rear] = dest;
            }
            adjList = adjList->next;
        }
    }
    printf("\n");
}

int main() {
    int V, choice;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    struct Graph* graph = createGraph(V);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add an edge\n");
        printf("2. Depth-First Search (DFS) traversal\n");
        printf("3. Breadth-First Search (BFS) traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int src, dest;
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                printf("Depth-First Search (DFS) traversal: ");
                bool visitedDFS[MAX_VERTICES] = { false };
                for (int i = 0; i < V; i++) {
                    if (!visitedDFS[i]) {
                        DFS(graph, i, visitedDFS);
                    }
                }
                printf("\n");
                break;
            case 3:
                printf("Enter the starting vertex for Breadth-First Search (BFS): ");
                int start;
                scanf("%d", &start);
                BFS(graph, start);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
