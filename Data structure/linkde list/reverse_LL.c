//program  for implementaion of linked list
//Shreyas Kamble 22610046

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node Node;
struct Node* newNode(int d){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=d;
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
    temp->next=node;
}
void Display(Node* ans){
    Node *temp=ans;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void search(int ele,Node* ans){
    Node *temp=ans;
    int f=1;
    if(ans==NULL){
        printf("List is Empty\n");
    }
    else{
        while(temp!=NULL){
            if(temp->data==ele){
                printf("Element Found\n");
                f=0;
                break;
            }
            temp=temp->next;
        }
        if(f==1){
            printf("Element not Found\n");
        }
    }
    
}
Node *reverse(Node* head){
    Node *pre=NULL;
    Node *curr=head;
    Node *forw=NULL;
    if(head==NULL){
        printf("List is Empty\n");
        return NULL;
    }
    else{
    while(curr!=NULL){
        forw=curr->next;
        curr->next=pre;
        pre=curr;
        curr=forw;
    }
    head=pre;
    return head;
    } 
}
int main(){
    insertatbegin(6);
    insertatend(8);
    insertatpos(9,2);
    insertatbegin(78);
    insertatend(56);
    Display(head);
    printf("Element present at head is: %d\n",head->data);
    int choice;
    printf("--------------------------------------------------------------\n\n");
    printf("Choose Option From Below: \n");
    printf(" 1.Reverse \n 2.Searching an Element\n 3.Display\n 4.Exit\n\n");
    printf("---------------------------------------------------------------\n\n");
    int i=1;
    Node *ans=NULL;
    while(i){
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            ans=reverse(head);
            Display(ans);
            printf("Element present at head is: %d\n",ans->data);
            break;
            case 2:
            int ele;
            printf("Enter the Element to be Search for: ");
            scanf("%d",&ele);
            search(ele,ans);
            break;
            case 3:
            Display(ans);
            break;
            case 4:
            i=0;
            printf("Exitting\n");
            break;
            default:
            printf("Enter the valid Input\n");
            break;
        } 
    }
    return 0;
}