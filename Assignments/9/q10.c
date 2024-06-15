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

int diameter(Node* root, int* height) {
    int lh = 0, rh = 0;
    int ldiameter = 0, rdiameter = 0;

    if (root == NULL) {
        *height = 0;
        return 0;
    }

    ldiameter = diameter(root->left, &lh);
    rdiameter = diameter(root->right, &rh);

    *height = (lh > rh ? lh : rh) + 1;

    return (lh + rh > ldiameter && lh + rh > rdiameter) ? lh + rh : (ldiameter > rdiameter ? ldiameter : rdiameter);
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
    int height = 0;
    printf("%d\n", diameter(nodes[0], &height));
    return 0;
}