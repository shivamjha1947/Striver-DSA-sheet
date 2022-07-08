void solve(int node, vector<int> adj[], vector<int> &vis, stack<int> &s){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            solve(it,adj,vis,s);
	        }
	    }
	    s.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> s;
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            solve(i,adj,vis,s);
	        }
	    }
	    vector<int> v;
	    while(!s.empty()){
	        v.push_back(s.top());
	        s.pop();
	    }
	    return v;
	}
