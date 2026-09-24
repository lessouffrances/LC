
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

        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        maxSum = max( {maxSum, node->val+right+left} );

        return node->val + max(left, right);
    }
};