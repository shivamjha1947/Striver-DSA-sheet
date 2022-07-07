 bool solve(vector<int> adj[], int vis[], int V, int c, int p)
    {
        vis[c]=1;
        
        for(auto i = adj[c].begin(); i!=adj[c].end(); i++)
        {
            if(!vis[*i])
            {
                if(solve(adj,vis,V,*i,c))
                    return true;
            }
            else
            {
                if(*i!=p)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V];
        for(int i=0;i<V;i++)
            vis[i]=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                if(solve(adj,vis,V,i,-1)){
                    return true;   
                }
        }
        return false;
         
    }
