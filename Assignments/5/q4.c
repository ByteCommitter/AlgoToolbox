#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertNode(struct Node* head, int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if(head==NULL){
        return temp;
    }

    struct Node * current= head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=temp;

    return head;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    struct Node* current = head;
    int len = 1;

    while (current->next != NULL) {
        current = current->next;
        len++;
    }

    current->next = head; // Make it circular list

    while (k--) {
        current = current->next;
    }

    head = current->next;
    current->next = NULL;

    return head;
}
void printList(struct Node *node) {
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    struct Node* list = NULL;
    int x;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        list = insertNode(list, x);
    }

    list = rotateRight(list, k % n);
    printList(list);

    return 0;
}