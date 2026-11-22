class Solution {
    public int[] runningSum(int[] nums) {
        int n=nums.length;
        int sum=0;
       for(int i=1;i<n;i++){
        nums[i]=nums[i]+nums[i-1];
       }
       return nums;
        
    }
}