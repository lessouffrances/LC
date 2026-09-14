class Solution 
{
    public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if (!root) return new TreeNode(val);
        // BST property
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        } else if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};