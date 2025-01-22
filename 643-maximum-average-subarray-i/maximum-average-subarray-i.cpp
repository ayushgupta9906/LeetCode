class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double s=0;
        for(int i=0;i<k;i++){
            s+=nums[i];

            

        }
        double maxs=s;
        for(int i=k;i<n;i++){
            s+=nums[i];
            s-=nums[i-k];
            maxs=max(maxs,s);

        }
        return maxs/k;
        
    }
    
};