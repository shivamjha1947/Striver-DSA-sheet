int minCoins(int coins[], int N, int V) 
	{ 
	    // Your code goes here
	    int t[N+1][V+1];
	    int i,j;
	    for(int i=0;i<N+1;i++){
	        for(int j=0;j<V+1;j++){
	            if(i==0){
	                t[i][j]=INT_MAX-1;
	            }else if(j==0){
	                t[i][j]=0;
	            }else{
	                if(coins[i-1]<=j){
	                    t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
	                }else{
	                    t[i][j]=t[i-1][j];
	                }
	            }
	        }
	    }
	    if(t[N][V]==INT_MAX-1){
	        return -1;
	    }
	    return t[N][V];
	    
	} 
