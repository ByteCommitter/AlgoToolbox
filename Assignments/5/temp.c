#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node *insertNode(struct node *head,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(head==NULL){
        temp->next = temp; // Point to itself
        return temp;
    }

    struct node *current=head;
    while(current->next!=head){
        current=current->next;
    }
    current->next=temp;
    //to make it circular
    temp->next=head;
    return head;
}

void findMeetingBlock(int n, int a, int b){
    struct node *head=NULL;
    for(int i=1;i<=n;i++){ // Loop should go up to n
        head=insertNode(head,i);
    }
    struct node*dwight=head;
    for(int i=1;i<a;i++){ // Start from 1
        dwight=dwight->next;
    }
    struct node *jim=head;
    for(int i=1;i<b;i++){ // Start from 1
        jim=jim->next;
    }

    while(dwight!=jim){
        dwight=dwight->next->next;
        jim=jim->next;
        if(dwight==head){
            printf("-1");
            return;
        }
    }
    printf("%d",dwight->data);
}

int main(){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    findMeetingBlock(n, a, b);
    return 0;
}