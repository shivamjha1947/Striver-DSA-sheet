    int maxLen(vector<int>&a, int n){   
        // Your code here
        int maxi=0;
        int count=0;
        unordered_map<int,int> m;
        for(int i=0;i<n-1;i++){
            a[i+1]+=a[i];
        }
        for(int i=0;i<n;i++){
            if(a[i]==0){
                count=i+1;
                maxi=max(maxi,count);
            }else{
                if(m.find(a[i])==m.end()){
                    m[a[i]]=i;
                }else{
                    count=i-m[a[i]];
                    maxi=max(maxi,count);
                }   
            }
        }
        return maxi;
    }
