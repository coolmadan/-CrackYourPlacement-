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
    void helper(TreeNode *root,vector<int>path,int targetSum,int &count){
        if(root==NULL)
            return;
        path.push_back(root->val);
        helper(root->left,path,targetSum,count);
        helper(root->right,path,targetSum,count);
        long long int  sum=0;
        for(int i=path.size()-1;i>=0;i--){
            sum+=path[i];
            if(sum==targetSum)
                count++;
        }
  
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        vector<int>path;
        helper( root,path,targetSum,count);
        return count;
    }
};
