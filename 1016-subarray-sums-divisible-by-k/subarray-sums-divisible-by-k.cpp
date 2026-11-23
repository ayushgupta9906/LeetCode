class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        mp[0]=1;
        int prefixsum=0;
        for(int n:nums){
            prefixsum+=n;
            int rem= ((prefixsum%k)+k)%k;
            count+=mp[rem];
            mp[rem]++;
        }
        return count;

        
    }
};