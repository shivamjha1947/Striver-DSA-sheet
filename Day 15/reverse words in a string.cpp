// can be done using stack also and inplace also
    string reverseWords(string s) {
        vector<string> v;
        string t="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(!t.empty()){
                    v.push_back(t);
                }
                t="";
            }else{
                t+=s[i];
            }
        }
        int x=t.size();
        for(int i=x-1;i>=0;i--){
            if(t[i]==' '){
                t.pop_back();
            }
        }
        if(!t.empty()){
            v.push_back(t);
        }
        t="";
        for(int i=v.size()-1;i>0;i--){
            t+=v[i]+" ";
        }
        t+=v[0];
        return t;
    }
