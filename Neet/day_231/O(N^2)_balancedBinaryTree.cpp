class Solution 
{
    public:
    bool isBalanced(TreeNode* root) 
    {
        if (!root) return true;
        int left = dfs(root->left);
        int right = dfs(root->right);
        bool isLocalBalanced = abs(right-left) <= 1;
        return isLocalBalanced && isBalanced(root->left) && isBalanced(root->right);
    }

    private:
    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        return 1 + max(left, right);
    }
};