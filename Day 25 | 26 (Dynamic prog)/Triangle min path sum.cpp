// Tabulation
int minimumTotal(vector<vector<int> > &triangle){
        int n=triangle.size();
        vector<vector<int> > dp(n,vector<int>(n,0));

        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){

                int down = triangle[i][j]+dp[i+1][j];
                int diagonal = triangle[i][j]+dp[i+1][j+1];

                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0];

    }

// Memoization
int solve(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& t){
        int n=triangle.size();
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i==n-1){
            return triangle[i][j]; 
        }
        int down=triangle[i][j]+solve(triangle,i+1,j,t);
        int diag=triangle[i][j]+solve(triangle,i+1,j+1,t);
        return t[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> t(n,vector<int>(n,-1));
        return solve(triangle,0,0,t);
    }
