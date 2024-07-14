/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int pathsum(TreeNode* root, int &max_sum){

        if(root == nullptr) return 0;

        int l_sum = max(0, pathsum(root->left, max_sum));
        int r_sum = max(0, pathsum(root->right, max_sum));
        
        max_sum = max(max_sum, root->val + l_sum + r_sum);

        return root->val + max(l_sum , r_sum);
    }

    int maxPathSum(TreeNode* root) {

        int max_sum = INT_MIN;
        pathsum(root, max_sum);

        return max_sum;
        
    }
};