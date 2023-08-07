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
    void helper(TreeNode*root,vector<int>&res){
        if(root==NULL)
            return;
        res.push_back(root->val);
        helper(root->left,res);
        helper(root->right,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>res;
        helper(root,res);
        int ans=0;
        sort(res.begin(),res.end());
        // for(int i=0;i<k;i++)
        //     if(i==k-1)
        //         ans= res[i];
        // return ans;
        return res[k-1];
    }
};
