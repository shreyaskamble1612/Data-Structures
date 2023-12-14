

#include <stdio.h>
#include <stdlib.h>

struct Tnode {
    int data;
    struct Tnode* left;
    struct Tnode* right;
};

struct Tnode* createnode(int data) {
    struct Tnode* newnode = (struct Tnode*)malloc(sizeof(struct Tnode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inorder(struct Tnode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Tnode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Tnode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Tnode* insert(struct Tnode* root, int data) {
    if (root == NULL) {
        return createnode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int main() {
    struct Tnode* root = createnode(10);
  
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. In-order Traversal\n");
        printf("2. Pre-order Traversal\n");
        printf("3. Post-order Traversal\n");
        printf("4. Insert a Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("In-order Traversal of the TREE : ");
                inorder(root);
                break;
            case 2:
                printf("Pre-order Traversal of the TREE : ");
                preorder(root);
                break;
            case 3:
                printf("Post-order Traversal of the TREE : ");
                postorder(root);
                break;
            case 4:
                printf("Enter the data to insert: ");
                int data;
                scanf("%d", &data);
                root = insert(root, data);
                printf("Node with data %d inserted into the tree.\n", data);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
