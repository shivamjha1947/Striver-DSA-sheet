bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited)
    {
        // Create a queue for BFS
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
 
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V - 1, 0);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, V, adj, vis))
                    return true;
            }
        }
    } 




// bool solve(vector<int> adj[], int vis[], int V, int c, int p)
//     {
//         vis[c]=1;
        
//         for(auto i = adj[c].begin(); i!=adj[c].end(); i++)
//         {
//             if(!vis[*i])
//             {
//                 if(solve(adj,vis,V,*i,c))
//                     return true;
//             }
//             else
//             {
//                 if(*i!=p)
//                     return true;
//             }
//         }
//         return false;
//     }
//     bool isCycle(int V, vector<int> adj[]) {
//         // Code here
//         int vis[V];
//         for(int i=0;i<V;i++)
//             vis[i]=0;
//         for(int i=0;i<V;i++)
//         {
//             if(!vis[i])
//                 if(solve(adj,vis,V,i,-1)){
//                     return true;   
//                 }
//         }
//         return false;
         
//     }
