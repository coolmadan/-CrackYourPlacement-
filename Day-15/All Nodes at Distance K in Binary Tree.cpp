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
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *>parent;
        queue<TreeNode *>pendingNodes;
        pendingNodes.push(root);
        while(pendingNodes.size()!=0){
            TreeNode * front= pendingNodes.front();
            pendingNodes.pop();
            if(front->left!=NULL){
                parent[front->left]=front;
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                parent[front->right]=front;
                pendingNodes.push(front->right);
            }
        }
       unordered_map<TreeNode *,bool>visited;
       visited[target]=true;
       pendingNodes.push(target);
       int dist=0;
       while(dist<k){
           TreeNode * front= pendingNodes.front();
           pendingNodes.pop();
           if(front->left!=NULL&&!visited[front->left]){
               pendingNodes.push(front->left);
               visited[front->left]=true;
           }
           if(front->right!=NULL&&!visited[front->right]){
               pendingNodes.push(front->right);
               visited[front->right]=true;
           }
           if(parent.count(front)&&!visited[parent[front]]){
               pendingNodes.push(parent[front]);
               visited[parent[front]]=true;
           }
           dist++;
       }
       vector<int>ans;
       while(!pendingNodes.empty()){

           ans.push_back(pendingNodes.front()->val);
           pendingNodes.pop();
       }
       return ans;
    }
};
