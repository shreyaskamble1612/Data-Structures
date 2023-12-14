//program  for implementaion of double linked list
//Shreyas Kamble 22610046

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
typedef struct Node Node;
struct Node* newNode(int d){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=d;
    temp->prev==NULL;
    temp->next=NULL;
    return temp;
}
Node *head=NULL;
void insertatbegin(int d){
    Node *temp=newNode(d);
        temp->next=head;
        head=temp;
}
void insertatend(int d){
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node *end=newNode(d);
    temp->next=end;
    end->prev=temp;
}
void insertatpos(int d,int pos){
    Node *temp=head;
    int c=1;
    while(c<pos-1){
        temp=temp->next;
        c++;
    }
    Node *node=newNode(d);
    node->next=temp->next;
    temp->next->prev==NULL;
    node->prev=temp;
    temp->next=node;
}
void Insertion(int d){
    int choice;
    printf("--------------------------------------------------------------\n\n");
    printf("Choose Option From Below: \n");
    printf(" 1.Insertion at front \n 2.Insertion at rear \n 3.Insertion at position\n4.Exit\n\n");
    printf("---------------------------------------------------------------\n\n");
    int i=1;
    while(i){
        printf("Enter Your Choice for Insertion: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insertatbegin(d);
            i=0;
            break;
            case 2:
            insertatend(d);
            i=0;
            break;
            case 3:
            int pos;
            printf("Enter the Position: ");
            scanf("%d",&pos);
            insertatpos(d,pos);
            i=0;
            break;
            case 4:
            i=0;
            printf("Exiting out Of Insertion\n");
            break;
            default:
            printf("Enter the valid Input\n");
            break;
        } 
    }
}
void Deletion(){
    int ele;
    printf("Enter the Position to be deleted: ");
    scanf("%d",&ele);
     Node *curr=head;
    Node *pre=NULL;
    int c=1;
    if(ele==1){
        Node *temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
    else{
    while(c<ele){
        pre=curr;
        curr=curr->next;
        c++;
    }
    pre->next=curr->next;
    curr->next->prev=pre;
    curr->prev=NULL;
    curr->next=NULL;
    free(curr);
    }
    }
void Display(Node* head){
    Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    printf("--------------------------------------------------------------\n\n");
    printf("Choose Option From Below: \n");
    printf(" 1.Insertion \n 2.Deletion \n 3.Display\n 4.exit\n\n");
    printf("---------------------------------------------------------------\n\n");
    int t=1;
    int c;
    while(t){
    printf("Enter Your Choice: ");
    scanf("%d",&c);
    switch(c){
        case 1:
        int d;
        printf("Enter the data to be Inserted: ");
        scanf("%d",&d);
        Insertion(d); 
       break;
        case 2:
        Deletion();
        break;
        case 3:
        Display(head);
        break;
        case 4:
        printf("Exitting\n");
        t=0;
        break;
        default:
        printf("Enter a  Valid Input\n");
    }
    }
    return 0;
}