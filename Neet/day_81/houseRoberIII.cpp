class Solution 
{
    public:
    int rob(TreeNode* root)
    {
        if (!root) return 0;
        return dfs(root);
    }
    private:
    unordered_map<TreeNode*, int> memo;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        if (memo.count(node)) return memo[node];

        int left = dfs(node->left);
        int right = dfs(node->right);

        int leftLeft = 0;
        int leftRight = 0;
        int rightLeft = 0;
        int rightRight = 0;

        if (node->left) {
            leftLeft = dfs(node->left->left);
            leftRight = dfs(node->left->right);
        }
        if (node->right) {
            rightLeft = dfs(node->right->left);
            rightRight = dfs(node->right->right);
        }

        // take the node
        int take = node->val + leftLeft + leftRight + rightLeft + rightRight;

        // skip the node
        int skip = left + right;

        int val = max(take, skip);
        memo[node] = val;
        return val;
    }
};
