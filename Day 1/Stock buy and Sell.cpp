Method 1)
int maxProfit(vector<int> &prices) {
    int maxPro = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    return maxPro;
}

Method 2)
int maxProfit(vector<int>& p) {
    int n=p.size();
    if(n==0 || n==1){
        return 0;
    }
    stack<int> s;
    int ans=0;
    s.push(p[0]);
    for(int i=1;i<n;i++){
        if(s.top()==p[i]){
            continue;
        }else if(s.top()<p[i]){
            ans=max(ans,p[i]-s.top());
        }else{
            while(!s.empty() && s.top()>p[i]){
                s.pop();
            }
            s.push(p[i]);
        }
    }
    return ans;
}
