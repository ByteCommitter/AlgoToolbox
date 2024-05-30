/*
Sunderlal is recently investing a lot in stocks. One day he got some insider information on
n stocks, but did not have the capital to invest. So, he decided to ask Jethalal for the money.
Although Jethalal was pretty suspicious about the plan, he had no choice but to give him 1 crore
rupees to invest otherwise Daya would not talk to him.
Now Sunderlal being Sunderlal, he read the stocks’ list in reverse order and invested accordingly.
This led to a huge loss of Jethalal’s money. Jethalal was disappointed and angry. But since he has
lots of connections in the stock market, he knows that his money would be recovered in no time.
All he has to do is to find out the original order of the stocks, which Sunderlal read wrong.
The stocks are given to you as a linked list in the way Sunderlal read it and you have to obtain the original list by changing the links of the linked list, as required.
Note: You are allowed to use only constant extra space and a singly linked list.
Input
The first line contains a single positive integer n (1 ≤ n ≤ 106
) - the number of stocks.
The second line contains n stocks a1, a2, . . . , an (1 ≤ ai ≤ 109
) - where ai
is the number of the i-th
stock.
Output
Find the original list of stocks.
input
5
1 2 6 23 3
output
3 23 6 2 1
input
6
1 5 2 9 11 4
output
4 11 9 2 5 1
*/

struct Node{
    int data;
    struct Node *next;
};


struct Node * createNode(int x){
    struct Node * head= malloc(sizeof(struct Node));
    head->data=x;
    head->next=NULL;
    return head;
}

struct Node * insertNode(int x,struct Node * list){
    struct Node * head=createNode(x);
    if(list==NULL){
        return head;
    }
    struct Node * current=list;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=head;
    return list;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main(){
    int n;
    scanf("%d",&n);
    struct Node * list=NULL;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        list=insertNode(x,list);
    }
    list = reverseList(list);
    printLinkedList(list);
}

