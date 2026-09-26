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

        if (!node->left) return right+1;
        if (!node->right) return left+1;

        return min(left, right)+1;
    }
};