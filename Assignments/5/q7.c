#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertNode(struct Node* head, int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if(head == NULL){
        temp->next = temp; // Point to itself
        return temp;
    }

    struct Node * current = head;
    while(current->next != head){
        current = current->next;
    }
    current->next = temp;
    temp->next = head; // Make it circular

    return head;
}

int findMeetingBlock(int n, int a, int b) {
    struct Node* head = NULL;
    for(int i = 1; i <= n; i++) {
        head = insertNode(head, i);
    }

    struct Node* dwight = head;
    for(int i = 1; i < a; i++) {
        dwight = dwight->next;
    }

    struct Node* jim = head;
    for(int i = 1; i < b; i++) {
        jim = jim->next;
    }

    while(dwight != jim) {
        dwight = dwight->next->next;
        jim = jim->next;
        if(dwight == head) {
            return -1; // Dwight made a full circle without meeting Jim
        }
    }

    return dwight->data;
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    printf("%d\n", findMeetingBlock(n, a, b));
    return 0;
}