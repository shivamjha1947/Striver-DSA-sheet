int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        int i=0;
        for(;i<k;i++){
            q.push(nums[i]);
        }
        for(;i<nums.size();i++){
            if(q.top()<nums[i]){
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
