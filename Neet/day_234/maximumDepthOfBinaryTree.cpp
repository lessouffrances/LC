class Solution 
{
    public:
    int maxDepth(TreeNode* root) 
    {
        return dfs(root);
    }

    private:
    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        int leftDepth = dfs(node->left);
        int rightDepth = dfs(node->right);
        return max(leftDepth, rightDepth)+1;
    }
};