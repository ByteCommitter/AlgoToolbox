#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* SortedMerge(struct Node* a, struct Node* b) {
    struct Node* result = NULL;

    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);

    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}

void printList(struct Node *node) {
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node* newNode(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    struct Node *first = NULL, *second = NULL;

    int x;
    scanf("%d", &x);
    first = newNode(x);
    struct Node *temp = first;
    for(int i = 1; i < m; i++) {
        scanf("%d", &x);
        temp->next = newNode(x);
        temp = temp->next;
    }

    scanf("%d", &x);
    second = newNode(x);
    temp = second;
    for(int i = 1; i < n; i++) {
        scanf("%d", &x);
        temp->next = newNode(x);
        temp = temp->next;
    }

    struct Node* res = SortedMerge(first, second);
    printList(res);

    return 0;
}