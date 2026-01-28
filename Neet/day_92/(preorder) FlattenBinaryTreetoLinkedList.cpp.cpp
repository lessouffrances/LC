class Solution 
{
    public:
    void flatten(TreeNode* root) 
    {
        TreeNode* prev = nullptr;
        preorder(root, prev);
    }
        
    private:
    void preorder(TreeNode* node, TreeNode*& prev) {
        if (!node) return;

        TreeNode* left = node->left;
        TreeNode* right = node->right;

        if (prev) {
            prev->right = node;
            prev->left = nullptr;
        }
        prev = node;

        preorder(left, prev);
        preorder(right,prev);
    }
};