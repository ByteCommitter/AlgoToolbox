//longest path between any two nodes...
//does not need to pass via root

//we can calculate this by checking the sum of lh and rh at every node...
#include<stdio.h>
#include<stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
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

struct Node * insertNode(int x,struct Node * root){
    if(root==NULL){
        root=createNode(x);
        return root;
    }
    if(x<root->val){
        root->left=insertNode(x,root->left);
        return root;
    }
    else{
        root->right=insertNode(x,root->right);
        return root;
    }
}

int getHeight(struct Node * root){
    if(root==NULL){
        return 0;
    }
    int lh=getHeight(root->left);
    int rh=getHeight(root->right);
    return 1+(lh>rh?lh:rh);
}

int maxDiameter(struct Node * root){
    if(root==NULL){
        return 0;
    }
    int lh=getHeight(root->left);
    int rh=getHeight(root->right);

    int ld=maxDiameter(root->left);
    int rd=maxDiameter(root->right);

    return max(lh+rh, max(ld, rd));
}




int main(){
    struct Node * root=malloc(sizeof(struct Node));
    root=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        root=insertNode(x,root);
    }
    int sum=0;
    
    printf("%d",maxDiameter(root));
}

