class Solution 
{
    public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        dfs(root);
        return maxDiameter;
    }

    private:
    int maxDiameter = INT_MIN;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int leftDepth = dfs(node->left);
        int rightDepth = dfs(node->right);

        maxDiameter = max(leftDepth+rightDepth, maxDiameter);
        return 1+max(leftDepth, rightDepth);
    }
};