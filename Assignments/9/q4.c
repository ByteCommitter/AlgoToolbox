/*
Since everyone thought that Assignment 8 was very easy, Nom and Kira decided to give the
toughest problem known to humanity.
The objective of this problem is to create a tree using its Inorder and Preorder traversals. Nom
and Kira wish you all the best for this problem.
Input
The first line of input contains n (1 ≤ n ≤ 3000) — the size of arrays a and b.
The second line of input contains n space separated integers a1, a2, . . . , an (1 ≤ ai ≤ 109
) which
denotes the Inorder traversal of the tree
The third line of input contains n space separated integers b1, b2, . . . , bn (1 ≤ bi ≤ 109
) which
denotes the Preorder traversal of the tree
Each value of a also appears in b.
Output
Print the Level-Order Traversal of the tree (with -1 where a node points to NULL).
input
5
3 9 20 15 7
9 3 15 20 7
output
3 9 20 -1 -1 15 7
input
6
1 2 3 4 5 6
4 2 1 3 5 6
output
4 2 5 1 3 -1 6
*/
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

int search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

struct Node* buildTree(int in[], int pre[], int inStrt, int inEnd, int* preIndex) {
    if (inStrt > inEnd)
        return NULL;
    struct Node* tNode = newNode(pre[*preIndex]);
    (*preIndex)++;
    if (inStrt == inEnd)
        return tNode;
    int inIndex = search(in, inStrt, inEnd, tNode->data);
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, preIndex);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);
    return tNode;
}

void printLevelOrder(struct Node* root) {
    if (root == NULL) return;
    struct Node* queue[3000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        struct Node* node = queue[front++];
        if (node != NULL) {
            printf("%d ", node->data);
            if (node->left != NULL || node->right != NULL) {
                queue[rear++] = node->left;
                queue[rear++] = node->right;
            }
        } else {
            printf("-1 ");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int in[n], pre[n];
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    int preIndex = 0;
    struct Node* root = buildTree(in, pre, 0, n - 1, &preIndex);
    printLevelOrder(root);
    return 0;
}