vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root){
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            vector<int> temp;
            while(k--){
                TreeNode* top=q.front();
                q.pop();
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
                temp.push_back(top->val);
            }
            v.push_back(temp);
        }
        return v;
    }
