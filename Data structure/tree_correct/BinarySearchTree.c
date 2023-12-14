//Name : Yash Kiran Patil
//PRN : 22610027

#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

struct BST* createNode(int value) {
    struct BST* newNode = (struct BST*)malloc(sizeof(struct BST));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BST* insert(struct BST* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if(value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

struct BST* deleteNode(struct BST* root, int value) {
    if (root == NULL) {
        return root;
    }
    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }else if (value > root->data){
        root->right = deleteNode(root->right, value);
    }else{
        if (root->left == NULL) {
            struct BST* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BST* temp = root->left;
            free(root);
            return temp;
        }

        struct BST* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void displayTree(struct BST* root) {
    if (root == NULL) {
        return;
    }

    printf("%d _ ", root->data);
    displayTree(root->left);
    displayTree(root->right);
}

struct BST* search(struct BST* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data){
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int findMin(struct BST* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int findMax(struct BST* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int countNodes(struct BST* node) {
    if (node == NULL)
        return 0;

    return 1 + countNodes(node->left) + countNodes(node->right);
}


void displayMenu() {
    printf("\n1. Insert\n2. Delete\n3. Display the TREE\n4. Search\n5. Find Minimum value in BST\n6. Find Maximum value in BST\n7. Count Nodes\n8. Exit\nEnter your choice: ");
}

int main() {
    struct BST* root = NULL;
    int choice, value;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Tree elements are: ");
                displayTree(root);
                printf("\n");
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("%d found in the tree.\n", value);
                } else {
                    printf("%d not found in the tree.\n", value);
                }
                break;
            case 5:
                printf("Minimum value found in the tree: %d\n", findMin(root));
                break;
            case 6:
                printf("Maximum value found in the tree: %d\n", findMax(root));
                break;
            case 7:
                printf("Number of nodes in the BST: %d\n", countNodes(root));
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
