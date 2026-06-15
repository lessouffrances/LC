class Solution 
{
    public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if (!root) return 0;

        dfs(root);
        return maxDiameter;
    }

    private:
    int maxDiameter = INT_MIN;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);
        maxDiameter = max(maxDiameter, left+right);

        return max(left, right)+1;
    }
};