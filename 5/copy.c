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


//Q1
struct node * addNumbers(struct node *first, struct node *second){
    struct node *res=NULL;
    int x=0;
    int y=0;
    while(first!=NULL){
        x=x*10+(first->data);
        first=first->next;
    }
    while(second!=NULL){
        y=y*10+(second->data);
        second=second->next;
    }
    int sum=x+y;
    while(sum!=0){
        res=insertNode(res,sum%10);
        sum=sum/10;
    }
    return res;
}
//Q2
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

//Q3
struct node *reverseList(struct node*head){
    struct node* prev=NULL;
    struct node*next=NULL;
    struct node * current =head;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

//Q4

void printList(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}
int main(){
    int m;
    int n;
    scanf("%d ",&m);
    struct node *first=NULL;
    struct node *second=NULL;

    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        first=insertNode(first,x);
    }

    /*for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        second=insertNode(second,x);
    }*/
    //Q1
    //struct node *res=addNumbers(first,second);
    //printList(res); 

    //Q2
    //struct node* mergedres=mergeList(first,second);
    //printList(mergedres);

    //Q3
    struct node*reversed=reverseList(first);
    printList(reversed);
}