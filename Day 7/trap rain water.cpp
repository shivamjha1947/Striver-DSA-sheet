Method 1)
int trap(vector<int>& height) {
        vector<int> l(height.size());
        vector<int> r(height.size());
        int ml=height[0];
        for(int i=0;i<height.size();i++){
            ml=max(ml,height[i]);
            l[i]=ml;
        }
        int mr=height[height.size()-1];
        for(int i=height.size()-1;i>=0;i--){
            mr=max(mr,height[i]);
            r[i]=mr;
        }
        int sum=0;
        for(int i=0;i<height.size();i++){
            int min_num=min(l[i],r[i]);
            sum+=min_num-height[i];
        }
        return sum;
    }

Method 2)
int trap(int A[], int n) {
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
