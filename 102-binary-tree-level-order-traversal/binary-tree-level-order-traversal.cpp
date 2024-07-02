class Solution {
public:
    void levelOrder(TreeNode* root, int level, vector<vector<int>> &answer)
    {
        if(!root)
            return;
        if(level == answer.size())
            answer.push_back({root->val});
        else
            answer[level].push_back(root->val);
        levelOrder(root->left , level+1, answer);
        levelOrder(root->right, level+1, answer);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root, 0, ans);
        return ans;
    }
};