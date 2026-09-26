class Solution 
{
    public:
    int minDepth(TreeNode* root) 
    {
        return dfs(root);
    }

    private:
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        if (!node->left) return 1+right;
        if (!node->right) return 1+left;

        return 1+min(left, right);
    }
};