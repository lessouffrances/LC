class Solution 
{
    public:
    int longestUnivaluePath(TreeNode* root) 
    {
        if (!root) return 0;
        dfs(root);
        return maxUniPath;
    }

    private:
    int maxUniPath = INT_MIN;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);

        int localLeft = 0, localRight = 0;
        if (node->left && node->val == node->left->val) {
            localLeft = 1 + left;
        }
        if (node->right &&node->val == node->right->val) {
            localRight = 1 + right;
        }

        maxUniPath = max( {localLeft, localRight, localLeft+localRight, maxUniPath} );
        // contributes: the length of the path (left/right)
        // given the value equals to the subtree root
        return max(localLeft, localRight);
    }
};