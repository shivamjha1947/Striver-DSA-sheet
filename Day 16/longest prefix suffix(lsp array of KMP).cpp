int lps(string s) {
        vector<int> l(s.size());
        int index =0;
        for(int i=1; i < s.size();){
            if(s[i] == s[index]){
                l[i] = index + 1;
                index++;
                i++;
            }else{
                if(index != 0){
                    index = l[index-1];
                }else{
                    l[i] =0;
                    i++;
                }
            }
        }
        return s.substr(0, index).size();
	}
