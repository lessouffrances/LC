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
    // post order: contributes to the height of the subtree
    int maxi = 0;
    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = dfs(node->left);
        int rightHeight = dfs(node->right);

        maxi = max( {maxi, leftHeight+rightHeight, leftHeight, rightHeight} );

        return 1 + max(leftHeight, rightHeight);
    }
};