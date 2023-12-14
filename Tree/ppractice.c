#include<stdio.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

//helper function
struct node* newnode(int data){
    // struct node* = (struct node*)malloc(sizeof(struct node))
    // struct node* = (struct node*)malloc(sizeof(struct node))/
    // struct node* = (struct node*)malloc(sizeof(struct node))
    struct node* node= (struct node*)malloc(sizeof(strict node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;

    return (node);

}
void printinorder(struct node* node){
    if(node == NULL){
        return;
    }
    printinorder(node->left);
    cout<<"%d "<<node->data;
    printinorder(node->right);
}


int main()
{
struct node* 
return 0;
}