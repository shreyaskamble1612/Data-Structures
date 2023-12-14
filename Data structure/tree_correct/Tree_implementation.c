
#include <stdio.h>
#include <stdlib.h>

struct Tnode {
    int data;
    struct Tnode* left;
    struct Tnode* right;
};

struct Tnode* createNode(int value){
    struct Tnode* newNode = (struct Tnode*)malloc(sizeof(struct Tnode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Tnode* InsertNode(struct Tnode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (root->left == NULL) {
        root->left = createNode(value);
    } else if (root->right == NULL) {
        root->right = createNode(value);
    } else {
        root->left = InsertNode(root->left, value);
    }

    return root;
}


struct Tnode* deleteTree(struct Tnode* root) {
    if (root == NULL) {
        return NULL;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
    return NULL;
}

void displayTree(struct Tnode* root) {
    if (root == NULL) {
        return;
    }

    printf("%d, ", root->data);
    displayTree(root->left);
    displayTree(root->right);
}



int main() {
    struct Tnode* root = NULL;
    int choice, value;

    while (1) {
      printf("\n1. Insertnode in Tree\n2. Delete the Tree\n3. Display Tree \n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to Insertnode: ");
                scanf("%d", &value);
                root = InsertNode(root, value);
                break;
            case 2:
                root = deleteTree(root);
                printf("Tree deleted.\n");
                break;
            case 3:
                printf("Tree elements are : ");
                displayTree(root);
                printf("\n");
                break;
            case 4:
                root = deleteTree(root);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
