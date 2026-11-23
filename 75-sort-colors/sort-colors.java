public class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;
        // Outer loop for each pass
        for (int i = 0; i < n - 1; i++) {
            boolean swapped = false;
            // Inner loop to compare adjacent elements
            for (int j = 0; j < n - 1 - i; j++) {
                if (nums[j] > nums[j + 1]) {
                    // Swap elements if they are in the wrong order
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    swapped = true;
                }
            }
            // If no elements were swapped, array is already sorted
            if (!swapped) {
                break;
            }
        }
    }
}