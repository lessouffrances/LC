class Solution 
{
    public:
    int maxPathSum(TreeNode* root) 
    {
        if (!root) return 0;
        dfs(root);
        return maxSum;
    }

    private:
    int maxSum = INT_MIN;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        // if there's negative sum on either side, give up the branch
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        // global updating
        maxSum = max( {maxSum, node->val+left, node->val+right, node->val+left+right} );

        // contribution margin
        return max(left, right) + node->val;
    }
};