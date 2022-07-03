// Method 1) Iterative
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val) {
                cur = cur -> left;
            } else if (p -> val > cur -> val && q -> val > cur -> val) {
                cur = cur -> right;
            } else {
                break;
            }
        }
        return cur;
    }
// Method 2) Recursive
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if ((root -> val > p -> val) && (root -> val > q -> val)) {
        return lowestCommonAncestor(root -> left, p, q);
    }
    if ((root -> val < p -> val) && (root -> val < q -> val)) {
        return lowestCommonAncestor(root -> right, p, q);
    }
    return root;
}
