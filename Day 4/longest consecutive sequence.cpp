    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans=0;
        for(auto i:nums){
            s.insert(i);
        }
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)!=s.end()){
                continue;
            }else{
                int t=nums[i];
                int count=0;
                while(s.find(t)!=s.end()){
                    count++;
                    t++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
