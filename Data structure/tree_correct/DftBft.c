#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Structure for a queue node (used in breadth-first traversal)
struct QueueNode {
    struct Node* node;
    struct QueueNode* next;
};

struct QueueNode* createQueueNode(struct Node* node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    return newNode;
}

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, struct Node* node) {
    struct QueueNode* newNode = createQueueNode(node);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

struct Node* dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    struct QueueNode* frontNode = queue->front;
    struct Node* node = frontNode->node;
    queue->front = frontNode->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(frontNode);
    return node;
}

void breadthFirstTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    printf("Breadth-First (BFT) traversal: ");
    while (queue->front != NULL) {
        struct Node* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left) {
            enqueue(queue, current->left);
        }
        if (current->right) {
            enqueue(queue, current->right);
        }
    }
    printf("\n");

    free(queue);
}

void preOrderDFS(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    printf("Pre-order DFS traversal: ");

    while (top >= 0) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right) {
            stack[++top] = current->right;
        }

        if (current->left) {
            stack[++top] = current->left;
        }
    }

    printf("\n");
}

struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

int main() {
    struct Node* root = createNode(10);
  

    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Breadth-First Traversal (BFT)\n");
        printf("2. Depth-First Traversal (DFT)\n");
        printf("3. Insert Node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                breadthFirstTraversal(root);
                break;
            case 2:
                preOrderDFS(root);
                break;
            case 3:
                printf("Enter the value to insert: ");
                int value;
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Node with data %d inserted into the tree.\n");
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
