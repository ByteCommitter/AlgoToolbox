#include<stdio.h>
#include<Stdlib.h>

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

void levelOrderTraversal(struct Node * root){
    struct Node ** queue=malloc(sizeof(struct Node *));
    int front=0;
    int rear=1;
    
    queue[front]=root;
    while(front!=rear){
        struct Node * currentNode=queue[front];
        front++;

        printf("%d ",currentNode->val);

        if(currentNode->left!=NULL){
            queue=realloc(queue,sizeof(struct Node *)*(rear+1));
            queue[rear]=currentNode->left;
            rear++;
        }
        if(currentNode->right!=NULL){
            queue=realloc(queue,sizeof(struct Node *)*(rear+1));
            queue[rear]=currentNode->right;
            rear++;
        }
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

    levelOrderTraversal(root);
}