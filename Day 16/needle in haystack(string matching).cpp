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

// Method 2) using KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j]) {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};
