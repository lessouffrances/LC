class Solution 
{
    public:
    int longestUnivaluePath(TreeNode* root) 
    {
        if (!root) return 0;
        dfs(root);
        return maxUnivaluePath;
    }

    private:
    // bottom-up, post-order
    int maxUnivaluePath = INT_MIN;

    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        int leftUniPath = 0, rightUniPath = 0;
        if (node->left && node->val == node->left->val) {
            leftUniPath = left+1;
        } 
        if (node->right && node->val == node->right->val) {
            rightUniPath = right+1;
        } 
        maxUnivaluePath = max( {maxUnivaluePath, leftUniPath, rightUniPath, leftUniPath+rightUniPath} );
        return max(leftUniPath, rightUniPath);
    }
};