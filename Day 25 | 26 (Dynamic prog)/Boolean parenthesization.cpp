int mod = 1003;
int dp[203][203][2];
int solve(string s,int i,int j,bool istrue){
        if(i>j){
            return 0;
        }
        if(i==j){
                if(istrue==true){
                    return s[i]=='T';
                }else{ 
                    return s[i]=='F';
                }
        }
        if(dp[i][j][istrue]!=-1){
            return dp[i][j][istrue];
        }    
        int ans = 0;
        int lt,lf,rt,rf;
        for(int k=i+1;k<j;k+=2){
                lt = solve(s,i,k-1,true);
                lf = solve(s,i,k-1,false);
                rt = solve(s,k+1,j,true);
                rf = solve(s,k+1,j,false);
                if(s[k]=='&'){
                        if(istrue==true){
                                ans = ans + lt*rt;
                        }else{
                                ans = ans + lt*rf + lf*rf + lf*rt;
                        }
                }else if(s[k]=='|'){
                        if(istrue==true){
                                ans = ans + lt*rt + lf*rt + lt*rf;
                        }else{
                                ans = ans + lf*rf;
                        }
                }else{
                        if(istrue==true){
                                ans = ans + lt*rf + lf*rt;
                        }else{
                                ans = ans + lt*rt + lf*rf;
                        }
                }
        }
        return dp[i][j][istrue] = ans%1003;
}

int countWays(int n, string s){
    memset(dp,-1,sizeof(dp));
    return solve(s,0,n-1,true);
}
