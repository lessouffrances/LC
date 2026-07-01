class Solution 
{
    public:
    int maxPathSum(TreeNode* root) 
    {
        dfs(root);
        return maxSum;
    }

    private:
    // postorder
    int maxSum = INT_MIN;

    int dfs(TreeNode* node)
    {
        // base case
        if (!node) return 0;

        // left & right
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));
        
        maxSum = max( { maxSum, left+node->val+right, left+node->val, node->val+right } );

        // this node contribution
        return max(left, right)+node->val;
    }
};