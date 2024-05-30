//Trick we could sovle by continuously referring ot the parent...
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

struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    return root;
}

int main() {
    struct Node* root = NULL;
    int n, A, B;
    scanf("%d %d %d", &n, &A, &B);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }
    struct Node* lca = LCA(root, A, B);
    printf("%d ", lca->data);
    return 0;
}