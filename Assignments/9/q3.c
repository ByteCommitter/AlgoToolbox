/*
After dropping out of college, Kira decided to become a Tollywood star like DJ Tillu. But he
ended up becoming a Wood-Cutter. He cut trees for a living. More the height of the tree, more
the money he’d get, thus allowing him to earn money to pursue his dream of becoming DJ Tillu’s
right shoe.
Since Kira has a lot of skill issue, he cut a random node of the tree he cut earlier, which may
or may not have reduced its height. Once a node is cut, the entire subtree will be gone. Help Kira
find the height of the remaining tree to calculate his expenses.
Input
The first line contains two positive integers n, k (1 ≤ n ≤ 106
, 1 ≤ k ≤ 109
) - the size of the array
representing the binary tree and the node which Kira cut off earlier.
The second line contains n distinct space separated integers a1, a2, . . . , an (1 ≤ ai ≤ 109
).
Output
Print a single integer - height of the remaining tree.
input
7 3
1 2 3 4 5 6 7
output
3
explanation
Consider the path: 1->2->4, it has a height 3.
input
output
2
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

struct Node* insertNode(int arr[], struct Node* root, int i, int n) {
    if (i < n && arr[i] != -1) {
        struct Node* temp = newNode(arr[i]);
        root = temp;
        root->left = insertNode(arr, root->left, 2 * i + 1, n);
        root->right = insertNode(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

struct Node* removeSubtree(struct Node* root, int k) {
    if (root == NULL) return NULL;
    if (root->data == k) return NULL;
    root->left = removeSubtree(root->left, k);
    root->right = removeSubtree(root->right, k);
    return root;
}

int height(struct Node* node) {
    if (node == NULL) return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = insertNode(arr, root, 0, n);
    root = removeSubtree(root, k);
    printf("%d\n", height(root));
    return 0;
}