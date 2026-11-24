class Solution {
    public void sortColors(int[] nums) {
        // Simple Bubble Sort as a baseline brute force approach
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = 0; j < nums.length - i - 1; j++) {
                // If adjacent elements are out of order, swap them
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
}