void solve(vector<vector<int>> &m,vector<string> &ans,string &s, int n, int r, int c){
        if(r==n-1 && c==n-1){
            ans.push_back(s);
            return;
        }
        if(c-1>=0 && m[r][c-1]==1){
            s+='L';
            m[r][c]=0;
            solve(m,ans,s,n,r,c-1);
            m[r][c]=1;
            s.pop_back();
        }
        if(c+1<n && m[r][c+1]==1){
            s+='R';
            m[r][c]=0;
            solve(m,ans,s,n,r,c+1);
            m[r][c]=1;
            s.pop_back();
        }
        if(r-1>=0 && m[r-1][c]==1){
            s+='U';
            m[r][c]=0;
            solve(m,ans,s,n,r-1,c);
            m[r][c]=1;
            s.pop_back();
        }
        if(r+1<n && m[r+1][c]==1){
            s+='D';
            m[r][c]=0;
            solve(m,ans,s,n,r+1,c);
            m[r][c]=1;
            s.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string s="";
        if(m[0][0]==1){
            solve(m,ans,s,n,0,0);
        }
        return ans;
        
    }
