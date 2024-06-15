/*
input
4 5
3 4 5 2
2 9 1 0 2
output
5 3 7 2 2
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertNode(struct Node* head, int data) {
    struct Node* temp= (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    return temp;
}

struct Node* addTwoLists(struct Node* first, struct Node* second) {
    struct Node* res = NULL;
    int x=0;
    int y=0;

    while(first!=NULL){
        x=x*10+first->data;
        first=first->next;
    }

    while(second!=NULL){
        y=y*10+second->data;
        second=second->next;
    }

    int sum=x+y;
    while(sum!=0){
        res=insertNode(res,sum%10);
        printf("%d ",sum%10);
        sum=sum/10;
    }
    return res;
}

void printList(struct Node *node) {
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    struct Node* first = NULL;
    struct Node* second = NULL;

    int x;
    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        first = insertNode(first, x);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        second = insertNode(second, x);
    }

    struct Node* res = addTwoLists(first, second);
    printList(res);

    return 0;
}