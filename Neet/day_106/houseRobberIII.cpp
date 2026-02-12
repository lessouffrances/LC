





class Solution 
{
    public:
    int rob(TreeNode* root) 
    {
        return dfs(root);
    }
    private:
    // postorder
    unordered_map<TreeNode*, int> memo;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        if (memo.count(node)) return memo[node];

        int left = dfs(node->left);
        int right = dfs(node->right);

        int leftLeft = 0, leftRight = 0;
        if (node->left) {
            leftLeft = dfs(node->left->left);
            leftRight = dfs(node->left->right);
        }
        int rightRight = 0, rightLeft = 0;
        if (node->right) {
            rightRight = dfs(node->right->right);
            rightLeft = dfs(node->right->left);
        }

        // for this node
        // take
        int take = leftLeft + leftRight + rightRight + rightLeft + node->val;
        
        // skip
        int skip = left + right;

        memo[node] = max(skip, take);
        return max(skip, take);
    }
};