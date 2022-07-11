//DP Tabulation
    int climbStairs(int n) {
        int t[n+1];
        for(int i=0;i<=n;i++){
            if(i==0 || i==1 ||i==2){
                t[i]=i;
            }else{
                t[i]=t[i-1]+t[i-2];
            }
        }
        return t[n];
    }
    
    // //Recursive
    int climbStairs(int n) {
        if(n==1 || n==2){
            return n;
        }
        return climbStairs(n-1)+climbStairs(n-2);
    }
