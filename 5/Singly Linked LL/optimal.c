#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node * insertNode(struct node *head, int data){
    struct node   *temp;

    temp=(struct node*) malloc(sizeof(struct node));
    temp->data=data; 
    temp->link=NULL;

    head->link=temp;
    return temp;
};


int main(){
    int m;
    int n;
    
    struct node *f1=malloc(sizeof(struct node));
    f1->data=45;
    f1->link=NULL;

    struct node *ptr=f1;
    ptr=insertNode(ptr,98);
    ptr=insertNode(ptr,45);
    ptr=insertNode(ptr,3);

    ptr=f1;

    while(f1!=NULL){
        printf("%d ",f1->data);
        f1=f1->link;
    }

}