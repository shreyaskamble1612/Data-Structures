#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;

}
struct node* createNode(int value){
    struct node* newnode = (struct node*)malloc(sizeof(strct node));

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}


struct node* insertnode(struct node* root,int value){
    if(root->NULL){
        return createNode(value);
    }

    if(root->left == NULL){
        root->left = createNode(value);
    }else if(root->right == NULL){
        root->right = createNode(value);
    }else{
        root->left = insertnode(root->left,value);
    }
}