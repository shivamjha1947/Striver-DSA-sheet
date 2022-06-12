vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int, int> cnt;
        for (auto num : nums){
            cnt[num]++;    
        } 
        for (auto i : cnt) {
            pq.push({i.second, i.first});
            if (pq.size() > k){
                pq.pop();   
            } 
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
