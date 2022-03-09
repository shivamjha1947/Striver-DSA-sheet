int maxSubArray(vector<int>& nums) {
    if(nums.size()==0){
        return 0;
    }
    int maxSum=nums[0];
    int curr=nums[0];
    for(int i=1;i<nums.size();i++){
        curr=max(curr+nums[i],nums[i]);
        maxSum=max(maxSum,curr);
    }
    return maxSum;
}
