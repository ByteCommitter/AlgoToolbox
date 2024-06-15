#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node* next;
} node;

void push_back(node** head, char new_data) {
    node* temp = (node*) malloc(sizeof(node));
    temp->data = new_data;
    temp->next = NULL;
    if (*head == NULL) {
        *head = temp;
        return;
    }
    node* last = *head;
    while (last->next != NULL) last = last->next;
    //temp->next = NULL;
    last->next = temp;
}

void push_front(node** head, char new_data) {
    node* temp = (node*) malloc(sizeof(node));
    temp->data = new_data;
    temp->next = *head;
    *head = temp;
}

char* is_palindrome(node* head, node* reversed) {
    while (head != NULL && reversed != NULL) {
        if (head->data != reversed->data) return "NO";
        head = head->next;
        reversed = reversed->next;
    }
    return "YES";
}

int main() {
    int n;
    scanf("%d", &n);

    node* head = NULL;
    node* reversed = NULL;
    char* str = malloc((n + 1) * sizeof(char)); // +1 for the null terminator
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
        push_back(&head, str[i]);
        push_back(&reversed, str[n-i-1]);
    }
    free(str);
    printf("%s\n", is_palindrome(head, reversed));
    return 0;
}