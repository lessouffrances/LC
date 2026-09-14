class Solution 
{
    public:
    int longestUnivaluePath(TreeNode* root) 
    {
        dfs(root);
        return res;
    }

    private:
    // bottom-up, post-order
    // return the longest left-only or right-only univalue path for this subtree
    int res = 0;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);

        int leftUnivaluePath = 0, rightUnivaluePath = 0;
        if (node->left && node->val == node->left->val) {
            leftUnivaluePath = left+1;
        }
        if (node->right && node->val == node->right->val) {
            rightUnivaluePath = right+1;
        }

        // update global 
        res = max( res, leftUnivaluePath+rightUnivaluePath );
        return max(leftUnivaluePath, rightUnivaluePath);
    }
}; 