#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertNode(struct Node* head, int data) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if(head==NULL){
        return temp;
    }
    struct Node* current= head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=temp;
    return head;
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

void printList(struct Node *node) {
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* list = NULL;
    int x;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        list = insertNode(list, x);
    }

    struct Node* reversed = reverseList(list);
    printList(reversed);

    return 0;
}