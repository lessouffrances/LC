class Solution 
{
    public:
    int rob(TreeNode* root) 
    {
        auto [withNode, withoutNode] = dfs(root);
        return max(withNode, withoutNode);
    }

    private:
    pair<int, int> dfs(TreeNode* node)
    {
        if (!node) return {0, 0};

        auto [leftWith, leftWithout] = dfs(node->left);
        auto [rightWith, rightWithout] = dfs(node->right);

        int withNode = node->val + leftWithout + rightWithout;
        int withoutNode = max(leftWith, leftWithout) + max(rightWith, rightWithout);

        return { withNode, withoutNode };
    }
};