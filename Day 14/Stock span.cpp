vector <int> calculateSpan(int price[], int n){
      // Your code here
      stack<int> s;
      vector <int> v;
      v.push_back(1);
      s.push(0);
      for(int i=1;i<n;i++){
          while(!s.empty() && price[i]>=price[s.top()]){
              s.pop();
          }
          if(s.empty()){
              v.push_back(i+1);
          }else{
              v.push_back(i-s.top());
          }
          s.push(i);
      }
      return v;
   }
