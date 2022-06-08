bool possible(bool graph[101][101],int c,int node, int col[],int n){
    for(int i=0;i<n;i++){
        if(graph[node][i]==1 && col[i]==c){
            return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101],int col[], int m, int n, int node){
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(possible(graph,i,node,col,n)){
            col[node]=i;
            if(solve(graph,col,m,n,node+1)){
                return true;
            }else{
                col[node]=0;
            }
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    int col[n]={0};
    return solve(graph,col,m,n,0);
}
