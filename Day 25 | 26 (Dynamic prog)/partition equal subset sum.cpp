bool solve(vector<int>& nums,int tar){
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool>(tar+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=tar){
            dp[0][nums[0]]=true;
        }
        for(int ind = 1; ind<n; ind++){
            for(int target= 1; target<=tar; target++){

                bool notTaken = dp[ind-1][target];

                bool taken = false;
                if(nums[ind]<=target)
                    taken = dp[ind-1][target-nums[ind]];

                dp[ind][target]= notTaken||taken;
            }
        }

        return dp[n-1][tar];
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        return solve(nums,sum/2);
    }
