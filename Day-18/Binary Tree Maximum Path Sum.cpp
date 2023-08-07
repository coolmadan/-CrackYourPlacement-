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
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        int maxi=INT_MIN;
        helper(root,maxi);
        return maxi;
    }
    int helper(TreeNode *root, int &maxi){
        //base case
        if(root==NULL)
            return 0;
        int leftSum=max(0,helper(root->left,maxi));
        int rightSum=max(0,helper(root->right,maxi));
        maxi=max(maxi,leftSum+rightSum+root->val);
        return root->val+max(leftSum,rightSum);
    }
};
