// Recursion
int solve(int nums[],int n,int target){
        if(n==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || nums[0]==target) return 1;
            return 0;
        }
        int M=pow(10,9)+7;
        int nonPick=solve(nums,n-1,target)%M;
        int pick=0;
        if(nums[n]<=target){
            pick=solve(nums,n-1,target-nums[n])%M;
        }    
        return (pick+nonPick)%M;
    }
    int perfectSum(int nums[] ,int n, int target) {
        return solve(nums,n-1,target);
    }
