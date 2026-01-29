class Solution 
{
    public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (!root) return nullptr;

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            // case 1: leaf
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            // case 2: one child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // 2 childen
            TreeNode* successor = leftMost(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
        
        return root;
    }
    private:
    TreeNode* leftMost(TreeNode* node) 
    { 
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};