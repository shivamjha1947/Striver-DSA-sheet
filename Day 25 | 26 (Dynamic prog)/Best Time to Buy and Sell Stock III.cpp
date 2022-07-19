// Best Space optimized

int maxProfit(vector<int>& Arr, int n)
{
    
    vector<vector<int>> ahead(2,vector<int> (3,0));
    
    vector<vector<int>> cur(2,vector<int> (3,0));
    
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                
                if(buy==0){// We can buy the stock
                    cur[buy][cap] = max(0+ahead[0][cap], 
                                -Arr[ind] + ahead[1][cap]);
                 }
    
                if(buy==1){// We can sell the stock
                    cur[buy][cap] = max(0+ahead[1][cap],
                                Arr[ind] + ahead[0][cap-1]);
                }
            }
        }
        ahead = cur;
    }
    
    return ahead[0][2];
   
}



// Memoize
int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp ){

    if(ind==n || cap==0) return 0; //base case
    
    if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];
        
    int profit;
    
    if(buy==0){// We can buy the stock
        profit = max(0+getAns(Arr,n,ind+1,0,cap,dp), 
                    -Arr[ind] + getAns(Arr,n,ind+1,1,cap,dp));
    }
    
    if(buy==1){// We can sell the stock
        profit = max(0+getAns(Arr,n,ind+1,1,cap,dp),
                    Arr[ind] + getAns(Arr,n,ind+1,0,cap-1,dp));
    }
    
    return dp[ind][buy][cap] = profit;
}


int maxProfit(vector<int>& prices, int n)
{
    // Creating a 3d - dp of size [n][2][3]
    vector<vector<vector<int>>> dp(n,
                                    vector<vector<int>> 
                                            (2,vector<int>(3,-1)));
    
    return getAns(prices,n,0,0,2,dp);
   
}


// Tabulation
int maxProfit(vector<int>& Arr, int n)
{
    // Creating a 3d - dp of size [n+1][2][3] initialized to 0
    vector<vector<vector<int>>> dp(n+1,
                                    vector<vector<int>> 
                                            (2,vector<int>(3,0)));
                                            
    // As dp array is intialized to 0, we have already covered the base case
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                
                if(buy==0){// We can buy the stock
                    dp[ind][buy][cap] = max(0+dp[ind+1][0][cap], 
                                -Arr[ind] + dp[ind+1][1][cap]);
                 }
    
                if(buy==1){// We can sell the stock
                    dp[ind][buy][cap] = max(0+dp[ind+1][1][cap],
                                Arr[ind] + dp[ind+1][0][cap-1]);
                }
            }
        }
    }
    
    
    return dp[0][0][2];
   
}
