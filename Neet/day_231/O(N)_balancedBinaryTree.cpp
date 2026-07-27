class Solution 
{
    public:
    bool isBalanced(TreeNode* root) 
    {
        return dfs(root) != -1;
    }

    private:
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int left = dfs(node->left);
        if (left == -1) return -1;
        int right = dfs(node->right);
        if (right == -1) return -1;

        if (abs(right-left) > 1) return -1;

        return 1 + max(left, right);
    }
};