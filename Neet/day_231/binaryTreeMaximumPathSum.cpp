class Solution 
{
    public:
    int maxPathSum(TreeNode* root) 
    {
        dfs(root);
        return res;
    }

    private:
    int res = INT_MIN;
    
    int dfs(TreeNode* node) 
    {
        if (!node) return;

        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        res = max( {res, node->val+left, node->val+right, node->val+left+right} );
        return node->val + max(left, right);
    }
};