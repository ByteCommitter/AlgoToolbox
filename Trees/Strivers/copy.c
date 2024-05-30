#include<stdio.h>
#include<stdlib.h>
struct Node {
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

struct Node * insertNode(int x, struct Node * root){
    if(root==NULL){
        return 0;
    }
    if(x<root->val){
        root->left=insertNode(x,root->left);
        return root;
    }
    else{
        root->right=insertNode(x,root->right);
    }
}

int findDepth(struct Node * root){
    if(root==NULL){
        return 0;
    }
    int lt=findDepth(root->left);
    int rt=findDepth(root->right);
    return lt>rt?lt:rt;
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
    struct Node * queue[3000];
    int front=0;
    int rear=1;

    queue[0]=root;
    while(front!=rear){
        struct Node * current=queue[front];
        //print current's value...

        if(current->left!=NULL){
            queue[rear]=current->left;
            rear++;
        }
        if(current->right!=NULL){
            queue[rear]=current->right;
            rear++;
        }
    }

}



int main(){
    int n;
    scanf("%d",&n);
    struct Node * root=NULL;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        root=insertNode(x,root);
    }
}
