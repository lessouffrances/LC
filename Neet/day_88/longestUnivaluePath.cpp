class Solution 
{
    public:
    int longestUnivaluePath(TreeNode* root) 
    {
        if (!root) return 0;
        dfs(root);
        return maxi;
    }
    private:
    int maxi = 0;
    // post order
    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);

        int leftUniPath = 0, rightUniPath = 0; 
        if (node->left && node->left->val == node->val) {
            leftUniPath = left + 1;
        }
        if (node->right && node->right->val == node->val) {
            rightUniPath = right + 1;
        }

        maxi = max({maxi, leftUniPath+rightUniPath, leftUniPath, rightUniPath});

        return max(leftUniPath, rightUniPath);
    }
};
   