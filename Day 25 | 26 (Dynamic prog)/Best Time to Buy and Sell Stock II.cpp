
// Best
int maxProfit(vector<int> &prices) {
        int ret = 0;
        for (int p = 1; p < prices.size(); ++p) 
          ret += max(prices[p] - prices[p - 1], 0);    
        return ret;
    }

// Memoize
long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp ){

    if(ind==n) return 0; //base case
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
    long profit;
    
    if(buy==0){// We can buy the stock
        profit = max(0+getAns(Arr,ind+1,0,n,dp), -Arr[ind] + getAns(Arr,ind+1,1,n,dp));
    }
    
    if(buy==1){// We can sell the stock
        profit = max(0+getAns(Arr,ind+1,1,n,dp), Arr[ind] + getAns(Arr,ind+1,0,n,dp));
    }
    
    return dp[ind][buy] = profit;
}


long getMaximumProfit(long *Arr, int n)
{
    //Write your code here
    
    vector<vector<long>> dp(n,vector<long>(2,-1));
    
    if(n==0) return 0;
    long ans = getAns(Arr,0,0,n,dp);
    return ans;
}


// Tabulation
long getMaximumProfit(long *Arr, int n)
{
    //Write your code here
    
    vector<vector<long>> dp(n+1,vector<long>(2,-1));
    
    //base condition
    dp[n][0] = dp[n][1] = 0;
    
    long profit;
    
    for(int ind= n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            if(buy==0){// We can buy the stock
                profit = max(0+dp[ind+1][0], -Arr[ind] + dp[ind+1][1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+dp[ind+1][1], Arr[ind] + dp[ind+1][0]);
            }
            
            dp[ind][buy]  = profit;
        }
    }
    return dp[0][0];
}
