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

//val+maxL+maxR

int maxPathSum(struct Node * root,int maxn){
    if(root==NULL){
        return 0;
    }
    int lsum=max(0,maxPathSum(root->left));
    int rsum=max(0,maxPathSum(root->right));

    maxn=(maxn>(lsum+rsum+root->val)?maxn:(lsum+rsum+root->val));
    return (root->val)+(lsum>rsum?lsum:rsum);
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
    
    printf("%d",maxPathSum(root,0));
}
