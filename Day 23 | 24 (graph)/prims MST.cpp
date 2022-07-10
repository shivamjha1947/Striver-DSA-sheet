// Method 1) N^2

void spanningTree(int N, vector<vector<int>> adj[]){
    // code here
    int parent[N];
    int key[N]; 
    bool mstSet[N]; 

    for (int i = 0; i < N; i++){ 
        key[i] = INT_MAX, mstSet[i] = false; 
    }
    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++){ 
        int mini = INT_MAX, u; 
        for (int v = 0; v < N; v++) {
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v; 
        }
        mstSet[u] = true; 
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }

    } 
}

// Method 2) Optimized
void spanningTree(int N, vector<vector<int>> adj[]){
    int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});

    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
	              key[v] = weight; 
                pq.push({key[v], v});    
            }
        }       
    } 
}
