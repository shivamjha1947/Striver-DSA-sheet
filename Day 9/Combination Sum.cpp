void solve(vector<int>& arr, vector<int> &temp, int t, vector<vector<int>> &ans, int ind){
        int n=arr.size();
        if(ind==n){
            if(t == 0) {
                ans.push_back(temp); 
            }
            return;
        }
        if(arr[ind]<=t){
            temp.push_back(arr[ind]);
            solve(arr,temp,t-arr[ind],ans,ind);
            temp.pop_back();    
        }
        solve(arr,temp,t,ans,ind+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int t) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(arr, temp, t, ans, 0);
        return ans;
    }
