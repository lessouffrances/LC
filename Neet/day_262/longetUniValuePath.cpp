class Solution 
{
    public:
    int longestUnivaluePath(TreeNode* root) 
    {
        dfs(root);
        return maxUnivalueLen;
    }

    private:
    int maxUnivalueLen = 0;

    // bottom-up, post-order
    // return the maxUnivalueLen of this subtree
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);
        int leftUnivalueLen = 0, rightUnivalueLen = 0;

        if (node->left && node->left->val == node->val) {
            leftUnivalueLen = left+1;
        }
        if (node->right && node->right->val == node->val) {
            rightUnivalueLen = right+1;
        }

        maxUnivalueLen = max( {maxUnivalueLen, leftUnivalueLen, rightUnivalueLen, 
            leftUnivalueLen+rightUnivalueLen} );
        
        return max( {leftUnivalueLen, rightUnivalueLen} );
    }
};