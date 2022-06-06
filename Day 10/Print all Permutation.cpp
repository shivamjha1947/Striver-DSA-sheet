//Method 1) use hashmap
void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> &t,int f[]){
        if(t.size()==nums.size()){
            ans.push_back(t);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!f[i]){
                f[i]=1;
                t.push_back(nums[i]);
                solve(nums,ans,t,f);
                t.pop_back();
                f[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        int f[nums.size()];
        for(int i=0;i<nums.size();i++){
            f[i]=0;
        }
        solve(nums,ans,t,f);
        return ans;
    }

// Method 2) without extra space
void recurPermute(int index,vector<int> &nums,vector<vector<int>> &ans){
      if(index==nums.size()){
        ans.push_back(nums);
        return;
      }
      for(int i=index;i<nums.size();i++){
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
      }
    }

    vector<vector<int>> permute(vector<int> &nums){
      vector<vector<int>> ans;
      recurPermute(0, nums, ans);
      return ans;
    }
