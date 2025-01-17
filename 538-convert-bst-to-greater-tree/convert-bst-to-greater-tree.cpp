class Solution {
public:
    int curr_sum;
    void traverse(TreeNode* node){
        // Go right
        if(node->right) traverse(node->right);
        
        curr_sum+=node->val;
        node->val=curr_sum;
        
        if(node->left) traverse(node->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        
        curr_sum=0;
        traverse(root);
        return root;
    }
};