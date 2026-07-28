class Solution 
{
    public:
    int rob(TreeNode* root) 
    {
        return dfs(root);
    }

    private:
    // contributes: up until this node, what's the max robbed value?
    unordered_map<TreeNode*, int> memo;
    
    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        if (memo.count(node)) return memo[node];

        // take this node
        int take = node->val;
        if (node->left) {
            take += dfs(node->left->left);
            take += dfs(node->left->right);
        }
        if (node->right) {
            take += dfs(node->right->left);
            take += dfs(node->right->right);
        }

        // skip this node
        int skip = 0;
        if (node->left) {
            skip += dfs(node->left);
        }
        if (node->right) {
            skip += dfs(node->right);
        }

        memo[node] = max(take, skip);
        return max(take, skip);
    }
};