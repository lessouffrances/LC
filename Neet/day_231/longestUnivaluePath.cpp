class Solution 
{
    public:
    int longestUnivaluePath(TreeNode* root) 
    {    
        if (!root) return 0;
        dfs(root);
        return res;
    }

    private:
    int res = INT_MIN;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);
        int leftUniPath = 0, rightUniPath = 0;
        
        if (node->left && node->left->val == node->val) {
            leftUniPath = left+1;
        }
        if (node->right && node->right->val == node->val) {
            rightUniPath = right+1;
        }

        res = max( {res, leftUniPath, rightUniPath} );
        return max(leftUniPath, rightUniPath);
    }

};