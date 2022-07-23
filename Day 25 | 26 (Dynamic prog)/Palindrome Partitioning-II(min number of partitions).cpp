bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
     
    int minCut(string str) {
        int n=str.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int minCost=INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(str,i,j)){
                    int cost=1+dp[j+1];
                    minCost=min(minCost,cost);
                }
            }
            dp[i]=minCost;
        }
        return dp[0]-1;
    }
