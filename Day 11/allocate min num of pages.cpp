bool allocate(int a[], int n, int mid, int m){
        int count=0;
        int temp=0;
        for(int i=0;i<n;i++){
            if(temp+a[i]>mid){
                count++;
                temp=a[i];
                if(temp>mid){
                    return false;
                }
            }else{
                temp+=a[i];
            }
        }
        if (count < m){
            return true;    
        } 
        return false;
    }
    int findPages(int a[], int n, int m) {
        //code here
        int l=a[0],h=accumulate(a,a+n,0);
        while(l<=h){
            int mid=(l+h)/2;
            if(!allocate(a,n,mid,m)){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return l;
    }
