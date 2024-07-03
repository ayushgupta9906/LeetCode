class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums.size() - 1, nums, dp);
    }
    
private:
    int solve(int n, vector<int>& nums, vector<int>& dp) {
        if (n < 0) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int take = nums[n] + solve(n - 2, nums, dp);
        int notTake = solve(n - 1, nums, dp);
        dp[n] = max(take, notTake);
        return dp[n];
    }
};