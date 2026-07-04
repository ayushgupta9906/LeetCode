class Solution {

    List<List<Integer>> ans = new ArrayList<>();

    private void backtrack(int index, int[] nums, List<Integer> current) {

        ans.add(new ArrayList<>(current));

        for (int i = index; i < nums.length; i++) {

            if (i > index && nums[i] == nums[i - 1])
                continue;

            current.add(nums[i]);

            backtrack(i + 1, nums, current);

            current.remove(current.size() - 1);
        }
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {

        Arrays.sort(nums);

        List<Integer> current = new ArrayList<>();

        backtrack(0, nums, current);

        return ans;
    }
}