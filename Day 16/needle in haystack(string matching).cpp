// Method 1) using maps
int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        if(m==0){
            return 0;
        }
        if(n<m){
            return -1;
        }
        unordered_map<string,int> d;
        int i=0;
        while(i<=n-m){
            string t=haystack.substr(i,m);
            if(d.find(t)==d.end()){
                d[t]=i;
            }
            i++;
        }
        if(d.find(needle)!=d.end()){
            return d[needle];
        }
        return -1;
    }
