#define ppi pair<int,pair<int,int>>
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int> > arr, int k){
       vector<int> op;
       priority_queue<ppi, vector<ppi>, greater<ppi> > queue;
       for (int i = 0; i < k; i++)
       queue.push({ arr[i][0], { i, 0 } });
       while (!queue.empty()) {
          ppi current_element = queue.top();
          queue.pop();
          int i = current_element.second.first;
          int j = current_element.second.second;
          op.push_back(current_element.first);
          if (j + 1 < k)
          queue.push({ arr[i][j + 1], { i, j + 1 } });
       }
       return op;
    }
};
