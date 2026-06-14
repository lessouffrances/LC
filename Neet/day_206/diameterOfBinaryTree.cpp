class Solution 
{
    public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if (!root) return 1;

        dfs(root);
        return maxDiameter;

    }

    private:
    int maxDiameter = INT_MIN;

    // postorder
    int dfs(TreeNode* node)
    {
        if (!node) return;
        int left = dfs(node->left);
        int right = dfs(node->right);

        maxDiameter = max(maxDiameter, left+right);
        return max(left, right)+1;
    }
};