#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data){
    struct Node * root= malloc(sizeof(Node));
    root->left=NULL:
    root->right=NULL;
    root->data=data;
    return root;
}

void insertNode(){

}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    
    }

    return 0;
}