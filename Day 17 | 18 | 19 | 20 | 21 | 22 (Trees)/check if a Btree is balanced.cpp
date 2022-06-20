pair<bool,int> bal(TreeNode* root){
        if(!root){
            return {true,0};
        }
        pair<bool,int> l=bal(root->left);
        pair<bool,int> r=bal(root->right);
        int x=abs(l.second-r.second);
        int h=1+max(l.second,r.second);
        if(l.first && r.first && x<=1){
            return {true,h};
        }
        return {false,h};
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        pair<bool,int> p=bal(root);
        return p.first;
    }
