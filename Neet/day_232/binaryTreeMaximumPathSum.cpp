class Solution 
{
    public:
    int maxPathSum(TreeNode* root) 
    {
        dfs(root);
        return maxPath;
    }

    private:
    int maxPath = INT_MIN;

    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));
        maxPath = max( {maxPath, node->val+left, node->val+right, node->val+right+left} );
        return node->val + max(left, right);
    }
};