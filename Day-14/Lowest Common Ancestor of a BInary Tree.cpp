/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findNode (vector<TreeNode *>&path,TreeNode * node,TreeNode *root){
        if(root==NULL)
            return false;
        path.push_back(root);
        if(root==node){
            return true;
        }

        if(findNode(path,node,root->left)||findNode(path,node,root->right))
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *>path1;
        vector<TreeNode *>path2;
        findNode(path1,p,root);
        findNode(path2,q,root);
        
        
        if (path1.empty() || path2.empty())
            return nullptr;

        TreeNode* ans = nullptr;
        for (int i = 0; i < min(path1.size(), path2.size()); i++) {
            if (path1[i] == path2[i]) {
                ans = path1[i];
            } else {
                break;
            }
        }

        return ans;
    }
};
