vector<int> nextSmaller(vector<int>& arr) {
        int n=arr.size();
        stack<int> s;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            while(!s.empty()){
                if(s.top()>=arr[i]){
                    s.pop();
                }else{
                    ans.push_back(s.top());
                    break;
                }
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            s.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
