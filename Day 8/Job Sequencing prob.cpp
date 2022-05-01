bool static comp(Job a, Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, comp);
        
        int prof=0;
        int noOfjobs=0;
        bool check[n]={0};
        
        for(int i=0; i<n; i++){
            
            for(int j= min(n,arr[i].dead-1); j>=0;j--){
                
                if(check[j]==0){
                    
                    noOfjobs++;
                    prof += arr[i].profit;
                    check[j]=1;
                    
                    break;
                }
            }
        }
        return {noOfjobs, prof};
    }
