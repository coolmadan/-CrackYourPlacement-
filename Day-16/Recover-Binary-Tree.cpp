/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrderTraversal(TreeNode *root,vector<TreeNode*>&res){
        if(root==NULL)
            return;
        inOrderTraversal(root->left,res);
        res.push_back(root);
        inOrderTraversal(root->right,res);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>res;
        inOrderTraversal(root,res);
        TreeNode*first=NULL;
        TreeNode*mid=NULL;
        TreeNode*last=NULL;
        int count=1;
        for(int i =1;i<res.size();i++){
            if(res[i]->val<res[i-1]->val&&count==1){
                first=res[i-1];
                mid=res[i];
                count=0;
            }
            if(res[i]->val<res[i-1]->val&&count==0){
                last=res[i];
            }
        }
        if(last==NULL)
            swap(first->val,mid->val);
        swap(first->val,last->val);
    }
};
