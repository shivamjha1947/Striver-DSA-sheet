int majorityElement(vector<int>& a) {
    int n=a.size();
    if(n==0){
        return -1;
    }
    if(n==1 || n==2){
        return a[0]; 
    }
    int count=0;
    int ele=0;
    for(int i=0;i<n;i++){
        if(count==0){
            ele=a[i];
        }
        if(ele==a[i]){
            count++;
        }else{
            count--;
        }
    }
    return ele;
}
