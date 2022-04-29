vector<vector<int>> threeSum(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> ans;
        if(n<3){
            return ans;
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                if(a[i]+a[j]+a[k]==0){
                    vector<int> v{a[i],a[j],a[k]};
                    ans.push_back(v);
                    while(j<k && a[j]==v[1]) 
                        j++;
                    while(j<k && a[k]==v[2]) 
                        k--;
                }else if(a[i]+a[j]+a[k]<0){
                    j++;
                }else{
                    k--;
                }
            }
            while (i+1<n && a[i+1]==a[i]){
                i++;
            }
        }
        return ans;
    }
