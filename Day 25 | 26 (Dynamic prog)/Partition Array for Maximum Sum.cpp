int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int maxi=INT_MIN,maxSum=INT_MIN,len=0;
            for(int j=i;j<min(n,i+k);j++){
                len++;
                maxi=max(maxi,arr[j]);
                maxSum=max(maxSum,len*maxi+dp[j+1]);
            }
            dp[i]=maxSum;
        }
        return dp[0];
    }
