class Codec {
public:

    string serialize(TreeNode* root) {
        return encode(root);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        TreeNode* root = NULL;
        
        while (getline (ss, item, '-')) 
            root = insert(root, stoi(item));

        return root;
    }
    
private:
    string encode(TreeNode* root) {
        if (!root)
            return "";
        return to_string(root->val) + "-" + encode(root->left)+encode(root->right);
    }
    
    TreeNode* insert(TreeNode* root, int val) {
        if (root == NULL) {
			TreeNode* temp=new TreeNode(val);
			return temp;
		}
    
		if (val<=root->val)
			root->left=insert(root->left,val);
    
		else
			root->right=insert(root->right,val);
    
		return root;
    }
};