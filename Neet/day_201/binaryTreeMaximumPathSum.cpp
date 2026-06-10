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

        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        maxSum = max( {maxSum, node->val + left + right, node->val + left, node->val + right} );
        return max(left, right)+node->val;
    } 
};