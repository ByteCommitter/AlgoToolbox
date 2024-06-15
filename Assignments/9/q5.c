#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    int i;
    for (i = strt; i <= end; i++)
        if (arr[i] > value)
            break;
    return i;
}

struct Node* buildTree(int post[], int* postIndex, int min, int max, int size) {
    if (*postIndex < 0)
        return NULL;
    struct Node* node = NULL;
    if (post[*postIndex] > min && post[*postIndex] < max) {
        node = newNode(post[*postIndex]);
        (*postIndex)--;
        if (*postIndex >= 0) {
            int i = search(post, 0, size - 1, node->data);
            node->right = buildTree(post, postIndex, node->data, max, size);
            node->left = buildTree(post, postIndex, min, node->data, size);
        }
    }
    return node;
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
    int post[n];
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    int postIndex = n - 1;
    struct Node* root = buildTree(post, &postIndex, INT_MIN, INT_MAX, n);
    printLevelOrder(root);
    return 0;
}