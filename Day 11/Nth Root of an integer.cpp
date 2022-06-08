int NthRoot(int n, int m)
	{
	    int l=1;
	    int r=m;
	    //int eps = 1e-6;
	    while(l<=r){
	        int mid = (l+r)/2;
	        if(pow(mid,n)==m){
	            return mid;
	        }
	        else if(pow(mid,n)>m){
	            r = mid-1;
	        }
	        else{
	            l = mid+1;
	        }
	    }
	    return -1;
	} 
