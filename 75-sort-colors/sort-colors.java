class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[minIdx]) {
                    minIdx = j;
                }
            }
            // Swap the found minimum element with the first element of unsorted part
            int temp = nums[i];
            nums[i] = nums[minIdx];
            nums[minIdx] = temp;
        }
    }
}
