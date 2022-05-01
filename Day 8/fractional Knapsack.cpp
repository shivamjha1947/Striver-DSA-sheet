bool static comp(Item &a, Item &b){
        return (double(a.value)/a.weight)>(double(b.value)/b.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here 
        sort(arr,arr+n,comp);
        double profit=0;
        for(int i=0;i<n;i++){
            if(W<=0){
                break;
            }
            if(arr[i].weight<=W){
                profit+=arr[i].value;
                W-=arr[i].weight;
            }else{
                profit+=double(arr[i].value)*(double(W)/arr[i].weight);
                W=0;
            }
        }
        return profit;
    }
