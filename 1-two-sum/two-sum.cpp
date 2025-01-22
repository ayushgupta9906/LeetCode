class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < nums.size(); i++) {
            numWithIndex.push_back({nums[i], i});
        }

        // Sort based on values
        sort(numWithIndex.begin(), numWithIndex.end());

        int s = 0, e = nums.size() - 1;

        while (s < e) {
            int sum = numWithIndex[s].first + numWithIndex[e].first; // Direct addition

            if (sum == target) {
                return {numWithIndex[s].second, numWithIndex[e].second};
            } else if (sum < target) {
                s++;
            } else {
                e--;
            }
        }

        return {}; // No solution found
    }
};
