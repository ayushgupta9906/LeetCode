/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean findTarget(TreeNode root, int k) {
        return find(root, new HashSet<>(), k);
    }

    public boolean find(TreeNode root, Set<Integer> set, int target) {
        if (root == null){
            return false;
        }

        if (set.contains(target - root.val)){
            return true;
        }    

        set.add(root.val);
        return find(root.left, set, target) || find(root.right, set, target);
    }
}