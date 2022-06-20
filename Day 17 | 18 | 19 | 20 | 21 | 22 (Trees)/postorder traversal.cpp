vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(root, nodes);
        return nodes;
    }
    
    void postorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        postorder(root -> left, nodes);
        postorder(root -> right, nodes);
        nodes.push_back(root->val);
    }
