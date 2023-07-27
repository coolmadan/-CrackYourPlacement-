
class Solution {
public:
    void helper(TreeNode*root,vector<string>&res,string s)
    {   if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL){
            s+=to_string(root->val);
            res.push_back(s);
            return;
        }         
        s+=to_string(root->val)+"->";
        helper(root->left,res,s);
        helper(root->right,res,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string>res;
       if(root==NULL)
        return res;
        string s="";
        helper(root,res,s);
        return res;
    }
};
