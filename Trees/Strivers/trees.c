#include<stdio.h>
#include<stdlib.h>

//creating a tree

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int x){
    struct Node * root=malloc(sizeof(struct Node));
    root->left=NULL;
    root->right=NULL;
    root->data=x;
    return root;
}

struct Node * insertNode(struct Node * root, int x){
    if(root==NULL){
        root=createNode(x);
        return root;
    }

    if(x<(root->data)){
        root->left=insertNode(root->left,x);//inside the bracket,s its neccesary to have something NULll if the node hasnt yet been created for it...
        //the irght side of the root now correctly points towards itself...
    }
    else{
        root->right=insertNode(root->right,x);
    }

}

//Traversals are very confusing...

void preOrderTraversal(struct Node * root){
    //root, left, right
    if(root==NULL){
        return ;
    }
    printf("%d ",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(struct Node * root){
    if(root==NULL){
        return ;
    }
    //left, root, right
    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);
}

void postOrderTraversal(struct Node * root){
    if(root==NULL){
        return ;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf(root->data);
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
    preOrderTraversal(root);
    printf("\n");
    inOrderTraversal(root);
}