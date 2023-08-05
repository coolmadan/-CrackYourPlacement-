 void flatten(TreeNode* root){
        TreeNode*x=root;
        while(x){
            if(x->left){
                TreeNode*y=x->left;
                while(y->right){
                    y=y->right;
                }
                y->right=x->right;
                x->right=x->left;
                x->left=NULL;
            }
            x=x->right;
        }
    }
