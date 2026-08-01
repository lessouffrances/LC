class Solution 
{
    public:
    int rob(TreeNode* root) 
    {
        auto [valueWithRoot, valueWithoutRoot] = dfs(root);
        return max(valueWithoutRoot, valueWithRoot);
    }

    private:
    // post-order, bottom-up
    // return [valueWith, valueWithout]
    pair<int, int> dfs(TreeNode* node)
    {
        if (!node) return { 0, 0 };

        auto [valueWithLeft, valueWithoutLeft] = dfs(node->left);
        auto [valueWithRight, valueWithoutRight] = dfs(node->right);

        // if with this node
        int valueWith = node->val + valueWithoutLeft + valueWithoutRight;
        // if without this node
        int valueWithout = max(valueWithLeft, valueWithoutLeft) 
        + max(valueWithRight, valueWithoutRight);

        return {valueWith, valueWithout};
    }
};