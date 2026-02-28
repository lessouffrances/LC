




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
    int maxPath = INT_MIN;
    // postorder
    // dfs contribution margin: the maximal path of the subtree
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        maxPath = max( {maxPath, left+right+node->val, node->val+left, node->val+right} );
        return node->val + max(left, right);
    }
};