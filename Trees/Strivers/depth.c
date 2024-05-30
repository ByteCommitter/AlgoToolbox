#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int x){
    struct Node * root=malloc(sizeof(struct Node));
    root->val=x;
    root->left=NULL;
    root->right=NULL;
    return root;
}

struct Node * insertNode(struct Node * root,int x){
    if(root==NULL){
        root=createNode(x);
        return root;
    }
    if(x<root->val){
        root->left=insertNode(root->left,x);
    }
    else{
        root->right=insertNode(root->right,x);
    }
}

void inOrderTraversal(struct Node * root){
    if(root==NULL){
        return ;
    }
    inOrderTraversal(root->left);
    printf("%d ",root->val);
    inOrderTraversal(root->right);
}

//height of Tree:
//1+max(left tree, right tree);
int maxHeight(struct Node * root){
    if(root==NULL){
        return 0;
    }
    int lh=maxHeight(root->left);
    int rh=maxHeight(root->right);

    return 1+(lh>rh?lh:rh);
}

//for checking for balanced Binary tree. every node should have 2 nodes
//they should be filled except or including the last level
//TO DO SO,
//we get the left height and right height of each node and check the difference, any violation, we return false....

int checkBalancedness(struct Node * root){
    if(root==NULL){
        return 0;
    }
    int lh=checkBalancedness(root->left);
    int rh=checkBalancedness(root->right);
    if(abs(lh-rh)>=1){
        return -1;
    }
    else{
        return 1+(lh>rh?lh:rh);
    }
}


int main(){
    struct Node * root=malloc(sizeof(struct Node));
    root=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        root=insertNode(root,x);
    }

    printf("%d",checkBalancedness(root));
}