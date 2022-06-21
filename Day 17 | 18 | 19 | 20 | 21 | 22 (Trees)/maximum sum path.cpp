int solve(TreeNode* node, int &maxi){
        if(node==NULL){
            return 0;
        }
        int l=max(0,solve(node->left,maxi));
        int r=max(0,solve(node->right,maxi));
        int t=node->val;
        int temp=t+l+r;
        maxi=max(maxi,temp);
        return t+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=0;
        solve(root,maxi);
        return maxi;
    }
