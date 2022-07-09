vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        // Code here
        vector<int> dis(V,INT_MAX);
        dis[s]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,s});
        while(!q.empty()){
            pair<int,int> p=q.top();
            int currDis=p.first;
            int node=p.second;
            q.pop();
            for(int i = 0 ; i<adj[node].size() ; i++){
                int n=adj[node][i][0],dist=adj[node][i][1];
                if(dis[n]>currDis+dist){
                    dis[n]=currDis+dist;
                    q.push({dis[n],n});
                }
            }
        }
        return dis;
    }
