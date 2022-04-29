// Method 1)
int removeDuplicates(vector<int>& A){
    int n=A.size();
    int count = 0;
    for(int i = 1; i < n; i++){
      if(A[i] == A[i-1]) count++;
      else A[i-count] = A[i];
    }
    return n-count;
}

// Method 2)
int removeDuplicates(vector<int>& a) {
    int n=a.size();
    if(n==0 || n==1){
        return n;
    }
    int count=1,j=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            continue;
        }else{
            a[j]=a[i];
            j++;
            count++;
        }
    }
    return count;
}
