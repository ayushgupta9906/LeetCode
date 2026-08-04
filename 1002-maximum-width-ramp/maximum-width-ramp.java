class Solution {
    public int maxWidthRamp(int[] nums) {
        int ans = 0;
        int n = nums.length;

        // Create a list of pairs (element, index)
        List<int[]> vp = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            vp.add(new int[]{nums[i], i});
        }

        // Sort the list based on the element values
        vp.sort((a, b) -> a[0] - b[0]);

        // Keep track of the minimum index seen so far
        int minIndex = vp.get(0)[1];

        // Traverse the sorted list to calculate the maximum width ramp
        for (int i = 1; i < n; i++) {
            int currentIndex = vp.get(i)[1];
            ans = Math.max(ans, currentIndex - minIndex);
            minIndex = Math.min(minIndex, currentIndex);
        }

        return ans;
    }
}