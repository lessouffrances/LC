




class Solution 
{
    public:
    void flatten(TreeNode* root) 
    {
        TreeNode* prev = nullptr;
        dfs(root, prev);
    }
    private:
    void dfs(TreeNode* node, TreeNode*& prev)
    {
        if (!node) return;

        TreeNode* left = node->left;
        TreeNode* right = node->right;

        if (prev) {
            prev->right = node;
            prev->left = nullptr;
        }
        prev = node;

        dfs(left, prev);
        dfs(right, prev);
    }
};