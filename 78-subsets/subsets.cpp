class Solution {
public:

    vector<int> v;
    vector<vector<int>> ans;

    void back(vector<int>& nums, int step)
    {
        if(step == nums.size())
        {
            ans.push_back(v);
        }
        else 
        {
            
            v.push_back(nums[step]);
            back(nums, step+1);
            v.pop_back();

            
            back(nums, step+1);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        back(nums, 0);
        return ans;
    }
};