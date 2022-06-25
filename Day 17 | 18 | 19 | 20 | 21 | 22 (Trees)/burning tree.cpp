void make(Node* root,vector<int> g[]){
      if(root==NULL){
          return;
      }
      if(root->left){
          g[root->data].push_back(root->left->data);
          g[root->left->data].push_back(root->data);
          make(root->left,g);
      }
      if(root->right){
           g[root->data].push_back(root->right->data);
           g[root->right->data].push_back(root->data);
          make(root->right,g);
      }
  }
  int minTime(Node* root, int target) 
  {
     vector<int> g[10005];
     make(root,g);
     queue<int> q;
     q.push(target);
     vector<bool> vis(10005,false);
     vis[target]=true;
     int level=0;
     while(!q.empty()){
         int n=q.size();
         for(int i=0;i<n;i++){
             int x=q.front();
             q.pop();
             for(auto v:g[x]){
                 if(!vis[v]){
                     q.push(v);
                     vis[v]=1;
                 }
             }
         }
         if(q.empty()){
             break;
         }
         level++;

     }
     return level;


  }
