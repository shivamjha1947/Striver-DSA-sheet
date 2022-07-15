bool static comp(pair<int,int> &a, pair<int,int> &b){
        if(a.second<b.second){
            return true;
        }
        return false;
    }
    int maxMeetings(int s[], int e[], int n)
    {
        // Your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({s[i],e[i]});
        }
        sort(v.begin(),v.end(),comp);
        int high=v[0].second;
        int count=1;
        for(int i=1;i<n;i++){
            if(v[i].first>high){
                count++;
                high=v[i].second;
            }
        }
        return count;
    }
