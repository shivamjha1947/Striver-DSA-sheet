vector<int> twoSum(vector<int>& nums, int x) {
    int n=nums.size();
    vector<int> ans;
    vector<int> v=nums;
    int i=0,j=n-1;
    sort(v.begin(),v.end());
    int a,b;
    while(i<j){
        if(v[i]+v[j]==x){
            a=v[i];
            b=v[j];
            break;
        }else if(v[i]+v[j]<x){
            i++;
        }else{
            j--;
        }
    }
    for(int i=0;i<n;i++){
        if(nums[i]==a || nums[i]==b){
            ans.push_back(i);
        }
    }
    return ans;
}
