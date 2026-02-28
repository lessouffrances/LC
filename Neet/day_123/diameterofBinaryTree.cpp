class Solution 
{
    public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (!root) return 0;
        dfs(root);
        return maxi;
    }
    private:
    // postorder
    // contribution margin: the maximal height of the subtree
    int maxi = 0;
    int dfs(TreeNode* node) 
    {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);
        maxi = max( {maxi, left, right, left+right} );
        return 1 + max(left, right); // contribute
    }
};