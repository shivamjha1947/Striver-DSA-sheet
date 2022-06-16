int celebrity(vector<vector<int>>& M, int n) 
    {
        // code here 
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        int n1,n2,x;
        while(s.size()!=1){
            n1=s.top();
            s.pop();
            n2=s.top();
            s.pop();
            if(M[n1][n2]==1){
                s.push(n2);
            }else if(M[n2][n1]==1){
                s.push(n1);
            }
        }
        x=s.top();
        for(int i=0;i<n;i++){
            if(i==x){
                continue;
            }else{
                if(M[i][x]==0){
                    return -1;
                }
                if(M[x][i]==1){
                    return -1;
                }
            }    
        }
        return x;
    }
