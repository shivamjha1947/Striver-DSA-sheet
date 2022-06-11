bool isPossible(vector<int>& a, int cows, int minDist) {
          int n=a.size();
          int cntCows = 1;
          int lastPlacedCow = a[0];
          for (int i = 1; i < n; i++) {
            if (a[i] - lastPlacedCow >= minDist) {
              cntCows++;
              lastPlacedCow = a[i];
            }
          }
          if (cntCows >= cows) return true;
          return false;
    }
    int maxDistance(vector<int>& a, int m) {
        sort(a.begin(),a.end());
        int n=a.size();
        int low = 1, high = a[n - 1] - a[0];
        while (low <= high) {
            int mid = (low + high) >> 1;
            if(isPossible(a, m, mid)){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high;
    }
