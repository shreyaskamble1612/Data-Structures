
#include <stdio.h>
#include <stdlib.h>

struct Tnode {
    int data;
    struct Tnode* left;
    struct Tnode* right;
};

struct Tnode* createNode(int data) {
    struct Tnode* newNode = (struct Tnode*)malloc(sizeof(struct Tnode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void iterativeInOrder(struct Tnode* root) {
    if (root == NULL)
        return;

    struct Tnode* stack[100];
    int top = -1;
    struct Tnode* current = root;

    printf("Iterative In-order Traversal: ");
    while (1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        if (top >= 0) {
            current = stack[top--];
            printf("%d ", current->data);
            current = current->right;
        } else {
            break;
        }
    }
}

void iterativePreOrder(struct Tnode* root) {
    if (root == NULL)
        return;

    struct Tnode* stack[100]; 
    int top = -1;

    printf("Iterative Pre-order Traversal: ");
    stack[++top] = root;

    while (top >= 0) {
        struct Tnode* current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

void iterativePostOrder(struct Tnode* root) {
    if (root == NULL)
        return;

    struct Tnode* stack1[100]; 
    struct Tnode* stack2[100]; 
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        struct Tnode* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL)
            stack1[++top1] = current->left;
        if (current->right != NULL)
            stack1[++top1] = current->right;
    }

    printf("Iterative Post-order Traversal: ");
    while (top2 >= 0) {
        struct Tnode* current = stack2[top2--];
        printf("%d ", current->data);
    }
}

int main() {
    struct Tnode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int choice;
    while (1){
        printf("\nMenu:\n");
        printf("1. Iterative In-order Traversal\n");
        printf("2. Iterative Pre-order Traversal\n");
        printf("3. Iterative Post-order Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                iterativeInOrder(root);
                break;
            case 2:
                iterativePreOrder(root);
                break;
            case 3:
                iterativePostOrder(root);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } 

    return 0;
}
