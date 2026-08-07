class Solution {
    private void preorder(TreeNode node, List<TreeNode> nodes) {
        if (node != null) {
            nodes.add(node);
            preorder(node.left, nodes);
            preorder(node.right, nodes);
        }
    }

    public void flatten(TreeNode root) {
        List<TreeNode> nodes = new ArrayList<>();

        preorder(root, nodes);

        TreeNode prev = root;

        for (int i = 1; i < nodes.size(); i++) {
            prev.left = null;
            prev.right = nodes.get(i);
            prev = prev.right;
        }
    }
}