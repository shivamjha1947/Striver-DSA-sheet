Method 1)
void solve(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      //element is picked
      solve(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      solve(ind + 1, arr, n, ans, sum);
    }
    vector < int > subsetSums(vector < int > arr, int n) {
      vector < int > ans;
      solve(0, arr, n, ans, 0);
      return ans;
    }

Method 2)    
    void solve(vector<int> &arr,vector<int> &ans,int ind){
        if(ind==arr.size()){
            return;
        }
        solve(arr,ans,ind+1);
        int x=ans.size();
        for(int i=0;i<x;i++){
            ans.push_back(arr[ind]+ans[i]);
        }
        return;
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        ans.push_back(0);
        solve(arr,ans,0);
        return ans;
    }
