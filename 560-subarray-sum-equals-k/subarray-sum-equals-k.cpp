class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        mp[0]=1;
        int prefixsum=0;
        for(int n:nums){
            prefixsum+=n;
            int required=prefixsum-k;
            count+=mp[required];
            mp[prefixsum]++;
        }
        return count;

        
    }
};