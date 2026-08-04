class Solution {
    public int maxWidthRamp(int[] nums) {
        int ans = 0;
        int n = nums.length;

        List<int[]> vp = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            vp.add(new int[]{nums[i], i});
        }

        vp.sort((a, b) -> a[0] - b[0]);
        int minIndex = vp.get(0)[1];
        for (int i = 1; i < n; i++) {
            int currentIndex = vp.get(i)[1];
            ans = Math.max(ans, currentIndex - minIndex);
            minIndex = Math.min(minIndex, currentIndex);
        }

        return ans;
    }
}