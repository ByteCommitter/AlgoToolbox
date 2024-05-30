/*
Jake Peralta and Amy Santiago were on a mission to see who could catch more criminals. Jake
caught n criminals and Amy caught m criminals. Since Amy is smart, she of course won, i.e., m
is strictly greater than n. Now, they brought in their perps (criminals) in the precinct, and made
them stand in a line each (Jake made his own line of perps, and Amy her own), in ascending order
of the number on their t-shirts. Now Captain Holt was furious and wanted all of them in one single
line in ascending order of their t-shirt numbers, but without any commotion.
You are given two linked lists with the t-shirt numbers of the perps and are required to find
an optimal way to help Peraltiago to make them stand in one single line. You are supposed to do
this without allocating new memory.
Input
The first line contains two integers n and m (1 ≤ n < m ≤ 106
) - the number of perps caught by
Jake and Amy respectively.
The second line contains n integers a1 < a2 < . . . < an (0 ≤ ai ≤ 109
) - t-shirt numbers of perps
caught by Jake.
The third line contains m integers b1 < b2 < . . . < bm (0 ≤ bi ≤ 109
) - t-shirt numbers of perps
caught by Amy.
Note: Two or more perps can have the same t-shirt numbers.
Output
A single linked list consisting of all the perps in order as described above.
input
3 4
33 345 346
1 22 333 4444
output
1 22 33 333 345 346 4444
input
1 4
4
2 4 54 445
output
2 4 4 54 445
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * createNode(int x){
    struct Node * head=malloc(sizeof(struct Node));
    head->next=NULL;
    head->data=x;
    return head;
}

struct Node * insertNode(int x, struct Node * list){
    struct Node * head= createNode(x);
    if(list==NULL){
        list=head;
        return list;
    }
    struct Node * current = list;
    while(current->next!=NULL){//always this is different
        current=current->next;
    }
    current->next=head;
    return list;
}

struct Node * MergeList(struct Node *l1, struct Node *l2 ){
    struct Node * head=malloc(sizeof(struct Node));
    head=NULL;
    while(l2!=NULL || l1!=NULL){
        if(l1!=NULL && l2!=NULL){
            int x=l1->data;
            int y=l2->data;
            if(x<y){
                head=insertNode(x,head);
                l1=l1->next;
                continue;
            }
            else{
                l2=l2->next;
                head=insertNode(y,head);
                continue;
            }
        }
        if(l1!=NULL){
            int x=l1->data;
            l1=l1->next;
            head=insertNode(x,head);
        }
        if(l2!=NULL){
            int x=l2->data;
            l2=l2->next;
            head=insertNode(x,head);
        }
    }
    return head;
}


void printLinkedList(struct Node *list){
    struct Node *current=list;
    while(current!=NULL){
        int x=current->data;
        printf("%d ",x);
        current=current->next;
    }
}


int main(){
    int m, n;
    scanf("%d %d",&m,&n);
    struct Node * l1=malloc(sizeof(struct Node));
    struct Node * l2=malloc(sizeof(struct Node));
    l1=NULL;
    l2=NULL;
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        l1=insertNode(x,l1);
    }
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        l2=insertNode(x,l2);
    }
    //m is always smaller than n...
    printLinkedList(MergeList(l1,l2));
}