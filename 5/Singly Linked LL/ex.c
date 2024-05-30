//singly linked list in C
#include<stdio.h>
#include<stdlib.h>
//making a linked list
struct Node{
    int data;//any other data type
    struct Node *link;
};//dont forget this semicolon

int FunctNode(struct Node *head){
    int cnt=0;
    if(head==NULL){
        return 0;
    }
    struct Node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        cnt++;
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return cnt;
}

//inserting a node at the end of the linked list

void insertNode(struct Node *head,int data){
    struct Node *ptr,*temp;
    ptr=head;

    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->link=NULL;

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
}

int main(){
    struct Node *head =NULL;
    head=(struct Node *)malloc(sizeof(struct Node));//we have typecasted the null pointer
    //malloc returns a void pointer, which we have typecasted

    head->data=45;//head pointer has the the data = 45
    head->link=NULL;//the link part of the structure

    //adding the second node
    struct Node *current=(struct Node *) malloc(sizeof(struct Node));
    current->data=98;
    current->link=NULL;
    head->link=current;


    //Adding the third node, we have to anaylze what head->link give
    //we can  reuse the pointer
    current=malloc(sizeof(struct Node));
    current->data=3;
    current->link=NULL;

    head->link->link=current;

    printf("\n%d\n", FunctNode(head));

    insertNode(head,67);

    printf("\n%d",FunctNode(head));
}

