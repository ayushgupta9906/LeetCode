import java.util.*;

public class Solution {
    // Helper to check if there is a unique subarray of length L using rolling hash
    private static boolean smallestUniqueSubarray(int[] nums, int L) {
        int n = nums.length;
        long MOD = 1000000007L;
        long BASE = 257L;
        
        long hash = 0;
        long baseL = 1;
        for (int i = 0; i < L; i++) {
            hash = (hash * BASE + nums[i]) % MOD;
            if (i < L - 1) {
                baseL = (baseL * BASE) % MOD;
            }
        }
        
        Map<Long, Integer> countMap = new HashMap<>();
        countMap.put(hash, 1);
        
        for (int i = L; i < n; i++) {
            hash = (hash - nums[i - L] * baseL % MOD + MOD) % MOD;
            hash = (hash * BASE + nums[i]) % MOD;
            countMap.put(hash, countMap.getOrDefault(hash, 0) + 1);
        }
        
        for (int count : countMap.values()) {
            if (count == 1) return true;
        }
        return false;
    }

    public static int smallestUniqueSubarray(int[] nums) {
        int low = 1, high = nums.length;
        int ans = nums.length;
        
        // Binary search on the length of the unique subarray
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (smallestUniqueSubarray(nums, mid)) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid length
            } else {
                low = mid + 1; // Need a larger length
            }
        }
        return ans;
    }

}