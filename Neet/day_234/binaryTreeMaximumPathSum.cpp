class Solution 
{
    public:
    int maxPathSum(TreeNode* root) 
    {
        dfs(root);
        return maxSum;
    }

    private:
    int maxSum = INT_MIN;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int leftDepth = max(0, dfs(node->left));
        int rightDepth = max(0, dfs(node->right));

        maxSum = max( {maxSum, leftDepth+rightDepth+node->val, rightDepth+node->val, leftDepth+node->val} );
        return node->val+max(leftDepth, rightDepth);
    }
};