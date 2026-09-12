class Solution 
{
    public:
    int rob(TreeNode* root) 
    {
        return dfs(root);
    }

    private:
    // return the maximum value for this subtree
    // bottom-up, post-order
    unordered_map<TreeNode*, int> memo;

    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        if (memo.count(node)) return memo[node];

        // take this node
        // then you can only take the nodes 2 layers below
        int take = 0;
        take += node->val;
        if (node->left) {
            take += dfs(node->left->left);
            take += dfs(node->left->right);
        }
        if (node->right) {
            take += dfs(node->right->left);
            take += dfs(node->right->right);
        }

        // skip this node
        // you can take nodes 1 layer below
        int skip = 0;
        skip += dfs(node->left);
        skip += dfs(node->right);

        int res = max(take, skip);
        memo[node] = res;
        return res;
    }
};