//we could sovel it by placing 1 0 ,2 1s, 4 2s, 8 3s.... depending on the number that's inserted into the array...
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void buildTree(Node* nodes[], int n) {
    int j = 1;
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }
}

int sumDistances(Node* node, int depth) {
    if (node == NULL) return 0;
    return depth + sumDistances(node->left, depth + 1) + sumDistances(node->right, depth + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    Node* nodes[n];
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        nodes[i] = (data == -1) ? NULL : newNode(data);
    }
    buildTree(nodes, n);
    printf("%d\n", sumDistances(nodes[0], 0));
    return 0;
}