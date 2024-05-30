#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node * createNode(int data){
    struct node *n=malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void insertNode(struct node** root, int arr[], int index, int n) {
    if (index < n) {
        *root = createNode(arr[index]);
        insertNode(&((*root)->left), arr, 2*index + 1, n);
        insertNode(&((*root)->right), arr, 2*index + 2, n);
    }
}

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

int maxPath(struct node * root, int* maxs){
    if(root==NULL){
        return 0;
    }
    int left=maxPath(root->left,maxs);
    int right=maxPath(root->right,maxs);
    *maxs=max(*maxs,left+right+root->data);
    return max(left,right)+root->data;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct node* root = NULL;
    insertNode(&root, arr, 0, n);
    int maxs=0;
    maxPath(root,&maxs);
    printf("%d ",maxs);
    return 0;
}

