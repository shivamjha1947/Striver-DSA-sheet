// Recursive
TreeNode* searchBST(TreeNode* root, int val) {
   if(root==NULL||root->val==val)
   {
       return root;
       
   }
        //how we use the return statement is the amazing thing to consider
        if(root->val<val)
        {
            return searchBST(root->right,val);
        }
        return searchBST(root->left,val);
    }

// Iterative
TreeNode* searchBST(TreeNode* root, int val) {
    while (root != nullptr && root->val != val) {
      root = (root->val > val) ? root->left : root->right;
    }
    return root;
}
