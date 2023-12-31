class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {x
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        int f=0;
        while(q.size()){
            vector<int> temp;
            int si=q.size();
            while(si--){
                TreeNode* te=q.front();
                q.pop();
                if(te->left!=NULL){
                    q.push(te->left);
                }
                if(te->right!=NULL){
                    q.push(te->right);
                }
                temp.push_back(te->val);
                
            }
            if(f==0){
                f=1;    
                ans.push_back(temp);
            }
            else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                f=0;
            }
        }
        return ans;
    }
};
