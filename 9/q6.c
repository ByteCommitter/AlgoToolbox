//can solve by sorting...
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

void kthLargestUtil(struct Node* root, int k, int* c) {
    if (root == NULL || *c >= k)
        return;
    kthLargestUtil(root->right, k, c);
    if (++*c == k) {
        printf("%d ", root->data);
        return;
    }
    kthLargestUtil(root->left, k, c);
}

void kthLargest(struct Node* root, int k) {
    int c = 0;
    kthLargestUtil(root, k, &c);
}

int main() {
    struct Node* root = NULL;
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }
    kthLargest(root, k);
    return 0;
}