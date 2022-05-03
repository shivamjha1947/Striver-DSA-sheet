void solve(vector<int>& arr, vector<int> &temp, int t, vector<vector<int>> &ans, int ind){
        int n=arr.size();
        if(t == 0) {
            ans.push_back(temp); 
            return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && arr[i]==arr[i-1]){
                continue;
            }
            if(arr[i]>t){
                break;
            }
            temp.push_back(arr[i]);
            solve(arr,temp,t-arr[i],ans,i+1);
            temp.pop_back();    
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int t) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        vector<int> temp;
        solve(arr, temp, t, ans, 0);
        return ans;
    }
