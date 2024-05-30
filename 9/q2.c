/*
/*
Nom and Akshoe were playing Poker the other day. Akshoe was new to it so Nom explained
the hands to him. According to Nom’s rules, you are given a community tree (a) and a tree in
hand (b). If the tree in hand is a perfect subtree of the community tree, you win. Otherwise, you lose.
A subtree of a binary tree is a tree that consists of a node in tree and all of this node’s descendants. The tree could also be considered as a subtree of itself.
Given community tree and tree in hand, find whether you will win or lose.
Input
The first line contains two positive integers n, m (1 ≤ m ≤ n ≤ 106
) - the size of the array
representing the two binary trees.
The second line contains n space separated integers a1, a2, . . . , an (1 ≤ ai ≤ 109
).
The second line contains m space separated integers b1, b2, . . . , bm (1 ≤ bi ≤ 109
).
Output
Print ”WIN” if you win, otherwise ”LOSS”.
input
7 3
1 2 3 4 5 6 7
3 6 7
output
WIN
input
8 3
8 12 13 -1 -1 6 7 5
13 6 7
output
LOSS
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * createNode(int x){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insertNode(int arr[], struct Node* root, int i, int n){
    if (i < n && arr[i] != -1){
        struct Node* temp = createNode(arr[i]);
        root = temp;

        root->left = insertNode(arr, root->left, 2 * i + 1, n);
        root->right = insertNode(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int areIdentical(struct Node *root1, struct Node *root2){
    if(root1 == NULL && root2 == NULL)
        return 1;
    if(root1 == NULL || root2 == NULL)
        return 0;

    return (root1->data == root2->data &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right));
}

int isSubtree(struct Node *T, struct Node *S){
    if(S == NULL)
        return 1;
    if(T == NULL)
        return 0;

    if(areIdentical(T, S))
        return 1;

    return isSubtree(T->left, S) || isSubtree(T->right, S);
}

int main(){
    int m, n;
    scanf("%d %d",&m, &n);
    int a[m];
    int b[n];
    for(int i=0; i<m; i++)
        scanf("%d", &a[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &b[i]);

    struct Node *T = insertNode(a, T, 0, m);
    struct Node *S = insertNode(b, S, 0, n);

    if(isSubtree(T, S))
        printf("WIN\n");
    else
        printf("LOSS\n");

    return 0;
}