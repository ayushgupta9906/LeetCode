

class Solution{
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        auto l = invertTree(root->left);
        auto r = invertTree(root->right);
        root->left=r;
        root->right=l;
        return root;
    }
};