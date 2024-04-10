class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        vector<int>::iterator it;
        it=find(nums.begin(),nums.end(),target);
        if(it!=nums.end())
        {
            return true;
        }
        return false;
        
    }
};