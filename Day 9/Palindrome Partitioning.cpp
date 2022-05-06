bool isPalindrome(string str,int s,int e){
        while(s<e){
            if(str[s]!=str[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    void solve(string s,vector<vector<string>> &ans,vector<string> &t,int ind){
        if (ind == s.size()) {
          ans.push_back(t);
          return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                t.push_back(s.substr(ind,i-ind+1));
                solve(s,ans,t,i+1);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> t;
        solve(s,ans,t,0);
        return ans;
    }
