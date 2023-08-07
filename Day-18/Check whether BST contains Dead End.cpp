

/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
bool isDeadEndhelper(Node* root, int min_val, int max_val) {
    if (root == nullptr) {
        return false;
    }

    if (min_val == max_val) {
        return true;  // Dead end found
    }

    bool left_dead_end = isDeadEndhelper(root->left, min_val, root->data - 1);
    bool right_dead_end = isDeadEndhelper(root->right, root->data + 1, max_val);

    return left_dead_end || right_dead_end;
}

bool isDeadEnd(Node* root) {
    return isDeadEndhelper(root, 1, INT_MAX);
}


//8 5 9 2 7 null null 1 null null null null null
//8 7 10 2 null 9 13
