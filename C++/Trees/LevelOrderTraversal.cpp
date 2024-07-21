#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (): val(0),left(NULL), right(NULL){}
    TreeNode(int x): val(x), left(NULL), right(NULL){}
}

vector<vector<int>> levelOrderTraversal(TreeNode*root){
    vector<vector<int>> traversal;
    if(root==NULL){
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            TreeNode * node=q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            level.push_back(node->val);
        }
        traversal.push_back(level);
    }
    return traversal;
}

int main(){
    
}