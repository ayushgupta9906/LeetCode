public class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        if (n == 0) return -1;
        
        // Compute suffix minima from right to left
        int[] suffixMin = new int[n];
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = Math.min(suffixMin[i + 1], nums[i]);
        }
        
        // Compute prefix maxima on the fly and check stability condition
        int runningMax = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            runningMax = Math.max(runningMax, nums[i]);
            if (runningMax - suffixMin[i] <= k) {
                return i; // Early exit on the first stable index
            }
        }
        
        return -1;
    }
}