/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<vector<Node*>>levelOrderTraversal(Node*root){
        vector<vector<Node*>>res;
        if(root==NULL)
            return res;
        queue<Node *>pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            int size=pendingNodes.size();
            vector<Node*>vec;
            for(int i=0;i<size;i++){
                Node*front=pendingNodes.front();
                vec.push_back(front);
                pendingNodes.pop();
                if(front->left!=NULL)
                    pendingNodes.push(front->left);
                if(front->right!=NULL)
                    pendingNodes.push(front->right);
            }
            res.push_back(vec);
        }
        return res;

    }
    Node* connect(Node* root) {
        vector<vector<Node*>>res;
        res=levelOrderTraversal(root);
        
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size();j++){
                if(j+1<res[i].size())
                    res[i][j]->next=res[i][j+1];
                else
                    res[i][j]->next=NULL;
            }
        }
        return root;
    }
};
