// Method 1
void sortColors(vector<int>& nums) {
    int zero=0, one=0, n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            zero++;
        }else if(nums[i]==1){
            one++;
        }
    }
    for(int i=0;i<zero;i++){
        nums[i]=0;
    }
    for(int i=zero;i<zero+one;i++){
        nums[i]=1;
    }
    for(int i=zero+one;i<n;i++){
        nums[i]=2;
    }
}

// Method 2
void sortColors(int A[], int n) {
    int j = 0, k = n - 1;
    for (int i = 0; i <= k; ++i){
        if (A[i] == 0 && i != j)
            swap(A[i--], A[j++]);
        else if (A[i] == 2 && i != k)
            swap(A[i--], A[k--]);
    }
}
