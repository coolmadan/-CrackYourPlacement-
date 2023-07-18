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
/*
    // int maxDepth(TreeNode *root){
    //     if(root==NULL)
    //         return 0;
    //     int left = maxDepth(root->left)+1;
    //     int right =maxDepth(root->right)+1;
    //     return max(left,right);
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //    int leftmax= maxDepth(root->left);
    //    int rightmax=maxDepth(root->right);
    //    return leftmax+rightmax; 
    // }
    correct approach but too much computational time and may sometime result in an error
    */
    //to reduce computational time I create a template class containing two data members one is height and the other one as diameter
    class Pair{
        public:
        int height=0;
        int diameter=0;
    };
    Pair helper(TreeNode*root)
    {
        if(root==NULL)
        {
            Pair P;
            P.height=0;
            P.diameter=0;
            return P;
        }
        Pair leftans=helper(root->left);
        Pair rightans=helper(root->right);
        int leftheight= leftans.height;
        int rightheight=rightans.height;
        int leftdiameter=leftans.diameter;
        int rightdiameter=rightans.diameter;
        int height=1+max(leftheight,rightheight);
        int diameter=max(leftheight+rightheight,max(leftdiameter,rightdiameter));
        Pair p;
        p.height=height;
        p.diameter=diameter;
        return p;
    }
    int diameterOfBinaryTree(TreeNode*root)
    {
        return helper(root).diameter;
    }
};
