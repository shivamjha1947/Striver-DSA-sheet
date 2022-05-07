string getPermutation(int n, int k) {
      int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
      }
      for (int i = 1; i <= n; i++) {
        numbers.push_back(i);
      }  
      string ans = "";
      //(k-1) due to 0 based indexing  
      k = k - 1;
      while (true) {
        ans=ans+to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);  
        if(numbers.size()==0){
            break;
        }
        k=k%fact;
        fact=fact/numbers.size();
      }
      return ans;
    }
