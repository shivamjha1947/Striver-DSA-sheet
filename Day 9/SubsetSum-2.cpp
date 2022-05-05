void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> &t,int ind){
        ans.push_back(t);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1] ){
                continue;
            }
            t.push_back(nums[i]);
            solve(nums,ans,t,i+1);
            t.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> t;
        solve(nums,ans,t,0); 
        return ans;
    }
