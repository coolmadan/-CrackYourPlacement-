class Solution {
public:
    bool helper(TreeNode* root, int sum, int targetSum) {
        if (root == nullptr)
            return false;
        
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return (sum == targetSum);
        }
        
        return helper(root->left, sum, targetSum) || helper(root->right, sum, targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, 0, targetSum);
    }
};
