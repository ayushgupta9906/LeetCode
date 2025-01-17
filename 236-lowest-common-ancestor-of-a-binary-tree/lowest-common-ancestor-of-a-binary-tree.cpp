/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* LCA(TreeNode* node, int n1 ,int n2) {

        if(node==nullptr)return NULL;

        if(node->val==n1 || node->val==n2)return node;

        TreeNode* leftLCA = LCA(node->left,n1,n2);
        TreeNode* rightLCA = LCA(node->right,n1,n2);

        if(leftLCA && rightLCA){
            return node;
        }

        if(leftLCA != NULL)return leftLCA;
        return rightLCA;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root,p->val, q->val);
    }
};