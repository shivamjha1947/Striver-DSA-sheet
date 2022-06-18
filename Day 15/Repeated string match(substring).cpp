bool issubstring(string str2, string rep1){
        int M = str2.length();
        int N = rep1.length();

        for (int i = 0; i <= N - M; i++) {
            int j;
            for (j = 0; j < M; j++)
                if (rep1[i + j] != str2[j])
                    break;
            if (j == M) 
                return true;
        }
     
        return false;
    }
     
    int repeatedStringMatch(string A, string B){
        int ans = 1;
        string S = A;
        while(S.size() < B.size()){
            S += A;
            ans++;
        }
        if (issubstring(B, S)) return ans;
        
        if (issubstring(B, S+A))
            return ans + 1;
        
        return -1;
    }
