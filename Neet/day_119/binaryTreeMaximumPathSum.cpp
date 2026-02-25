




class Solution 
{
    public:
    int maxPathSum(TreeNode* root)
    {
        if (!root) return 0;
        dfs(root);
        return maxPath;
    }
    private:
    // postorder
    int maxPath = INT_MIN;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int left = max(dfs(node->left), 0);
        int right = max(dfs(node->right), 0);

        maxPath = max( { maxPath, node->val+left+right, node->val+left, node->val+right } );
        return node->val + max(left, right);
    }
};