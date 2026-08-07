class Solution {
    public int minPatches(int[] nums, int n) {
        long reach = 1;
        int i = 0, patches = 0, m = nums.length;

        while (reach <= n) {
            if (i < m && nums[i] <= reach) {
                reach += nums[i++];
            } else {
                reach <<= 1;
                patches++;
            }
        }

        return patches;
    }
}