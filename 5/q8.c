#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* insertFront(struct Node* head, int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;
    if(head != NULL) head->prev = temp;
    return temp;
}

struct Node* insertBack(struct Node* head, int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    struct Node* last = head;
    if(head == NULL) {
        temp->prev = NULL;
        return temp;
    }
    while(last->next != NULL) last = last->next;
    last->next = temp;
    temp->prev = last;
    return head;
}

struct Node* deleteFront(struct Node* head) {
    if(head == NULL) return NULL;
    struct Node* temp = head;
    head = head->next;
    if(head != NULL) head->prev = NULL;
    free(temp);
    return head;
}

struct Node* deleteBack(struct Node* head) {
    if(head == NULL) return NULL;
    struct Node* last = head;
    while(last->next != NULL) last = last->next;
    if(last->prev != NULL) last->prev->next = NULL;
    else head = NULL;
    free(last);
    return head;
}

void printForward(struct Node* node) {
    if(node == NULL) {
        printf("-1\n");
        return;
    }
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void printBackward(struct Node* node) {
    if(node == NULL) {
        printf("-1\n");
        return;
    }
    while(node->next != NULL) node = node->next;
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }
    printf("\n");
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    struct Node* head = NULL;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        head = insertBack(head, x);
    }

    for(int i = 0; i < q; i++) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int x;
            scanf("%d", &x);
            head = insertFront(head, x);
        } else if(op == 2) {
            int x;
            scanf("%d", &x);
            head = insertBack(head, x);
        } else if(op == 3) {
            head = deleteFront(head);
        } else if(op == 4) {
            head = deleteBack(head);
        } else if(op == 5) {
            printForward(head);
        } else if(op == 6) {
            printBackward(head);
        }
    }

    return 0;
}