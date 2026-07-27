class Solution 
{
    public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        dfs(root); 
        return res;
    }
    
    private:
    int res = INT_MIN;
    // return the # of nodes including this one
    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        res = max(res, left+right);
        return 1 + max(left, right);
    }
};