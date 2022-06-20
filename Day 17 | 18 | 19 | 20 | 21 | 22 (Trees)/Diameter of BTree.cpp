// Method 1) using global var
  int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    int height(TreeNode* node, int& diameter) {
        if (!node) {
            return 0;
        }
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }

// Method 2) using pair
    pair<int,int> diameter(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> l=diameter(root->left);
        pair<int,int> r=diameter(root->right);
        int curr=l.second+r.second;
        int h=1+max(l.second,r.second);
        int mx=max(curr,max(l.first,r.first));
        return {mx,h};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return diameter(root).first;
    }    
