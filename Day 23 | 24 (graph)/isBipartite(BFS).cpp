bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> col(v,0);
        for(int i=0;i<v;i++){
            if(!col[i]){
                queue<int> q;
                q.push(i);
                col[i]=1;
                while(!q.empty()){
                    int t=q.front();
                    q.pop();
                    for (auto it: graph[t]){
                        if(!col[it]){
                            q.push(it);
                            col[it]=-col[t];
                        }else if(col[t]==col[it]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
