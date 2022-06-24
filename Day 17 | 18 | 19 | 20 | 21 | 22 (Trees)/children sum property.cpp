int isSumProperty(Node *root) {
        if(!root or !root->left and !root->right){
            return true;    
        } 
        int sum=0;
        if(root->left){ 
            sum += root->left->data;
        }    
        if(root->right){ 
            sum += root->right->data;
        }
        if(root->data != sum){ 
            return false;
        }
        if(isSumProperty(root->left) && isSumProperty(root->right)){ 
            return true;
        }
        return false;
    }
