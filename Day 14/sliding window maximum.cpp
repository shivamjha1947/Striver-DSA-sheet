vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<pair<int,int>> q;
        vector<int> v;
        for(int i=0;i<k;i++){
            while(!q.empty() && q.back().first<=a[i]){
                q.pop_back();
            }
            q.push_back({a[i],i});
        }
        v.push_back(q.front().first);
        for(int i=k;i<a.size();i++){
            if(!q.empty() && q.front().second==i-k){
                q.pop_front();
            }
            while(!q.empty() && q.back().first<=a[i]){
                q.pop_back();
            }
            q.push_back({a[i],i});
            v.push_back(q.front().first);
        }
        return v;
    }
