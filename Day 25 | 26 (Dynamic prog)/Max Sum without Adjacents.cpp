// Tabulation
int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	    dp[0]= arr[0];
        for(int i=1 ;i<n; i++){
            int pick = arr[i];
            if(i>1){
                pick += dp[i-2];
            }
            int nonPick = 0+ dp[i-1];
            dp[i]= max(pick, nonPick);
        }
        return dp[n-1];
	}


// Memoization
int solve(int *arr, int i,vector<int> &dp){
	    if(i==0){
	        return arr[i];
	    }
	    if(i<0){
	        return 0;
	    }
	    if(dp[i]!=-1){
	        return dp[i];
	    }
	    int l=arr[i]+solve(arr,i-2,dp);
	    int r=solve(arr,i-1,dp);
	    return dp[i]=max(l,r);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n==0){
	        return 0;
	    }
	    vector<int> dp(n,-1);
	    return solve(arr,n-1,dp);
	}
