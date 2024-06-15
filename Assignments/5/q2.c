//copy

#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node * next;
};

struct node *insertNode(struct node *head, int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(head==NULL){
        return temp;
    }

    struct node*current= head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=temp;
    return head;
}


struct node * mergeList(struct node* first, struct node* second){
    struct node* res=NULL;
    if(first==NULL){
        return second;
    }
    else if(second==NULL){
        return first;
    }

    if(first->data<=second->data){
        res=first;
        res->next=mergeList(first->next,second);
    }
    else{
        res=second;
        res->next=mergeList(first,second->next);
    }
    return res;
}

void printList(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}
int main(){
    int m;
    int n;
    scanf("%d %d",&m,&n);
    struct node *first=NULL;
    struct node *second=NULL;

    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        first=insertNode(first,x);
    }

    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        second=insertNode(second,x);
    }

    struct node* mergedres=mergeList(first,second);
    printList(mergedres);
}