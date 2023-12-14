#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct GraphAdjList {
    int V; 
    struct AdjList* array;
};

struct GraphAdjMatrix {
    int V; 
    int** adjMatrix;
};

struct GraphAdjList* createGraphAdjList(int V) {
    struct GraphAdjList* graph = (struct GraphAdjList*)malloc(sizeof(struct GraphAdjList));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }
    
    return graph;
}

void addEdgeAdjList(struct GraphAdjList* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = src;
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

struct GraphAdjMatrix* createGraphAdjMatrix(int V) {
    struct GraphAdjMatrix* graph = (struct GraphAdjMatrix*)malloc(sizeof(struct GraphAdjMatrix));
    graph->V = V;

    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    
    return graph;
}

// Function to add an edge to the graph using an adjacency matrix
void addEdgeAdjMatrix(struct GraphAdjMatrix* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void displayGraphAdjList(struct GraphAdjList* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* current = graph->array[i].head;
        printf("Adjacency list for vertex %d: ", i);
        while (current) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void displayGraphAdjMatrix(struct GraphAdjMatrix* graph) {
    printf("Adjacency matrix:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    struct GraphAdjList* graphAdjList = createGraphAdjList(V);
    struct GraphAdjMatrix* graphAdjMatrix = createGraphAdjMatrix(V);

    int choice, src, dest;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add an edge\n");
        printf("2. Display the graph (Adjacency List)\n");
        printf("3. Display the graph (Adjacency Matrix)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertices for the edge: ");
                scanf("%d %d", &src, &dest);
                addEdgeAdjList(graphAdjList, src, dest);
                addEdgeAdjMatrix(graphAdjMatrix, src, dest);
                break;
            case 2:
                displayGraphAdjList(graphAdjList);
                break;
            case 3:
                displayGraphAdjMatrix(graphAdjMatrix);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
