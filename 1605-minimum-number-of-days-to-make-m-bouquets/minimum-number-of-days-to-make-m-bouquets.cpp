class Solution {

public:
    int minDays(vector<int>& arr, int m, int k) {
        int low=*min_element(arr.begin(),arr.end());
        int high=*max_element(arr.begin(),arr.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int bouquetcount=0;
            int consecutivecount=0;
            for(int i=0;i<arr.size();i++){
                // int x=ceil((double)arr[i]/(double)mid);
                if(arr[i]<=mid){
                    consecutivecount++;
                    if(consecutivecount==k){
                        bouquetcount++;
                        consecutivecount=0;
                    }
                }else{
                    consecutivecount=0;
                }
            }
            if(bouquetcount>=m){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};