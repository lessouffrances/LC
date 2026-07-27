class Solution 
{
    public:
    int maxDepth(TreeNode* root) 
    {
        if (!root) return 0;
        return dfs(root);
    }

    private:
    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        return 1+max(left, right);
    }
};
