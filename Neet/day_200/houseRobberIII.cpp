
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
    // postorder
    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        if (memo.count(node)) return memo[node];

        // first-layered info 
        int left = dfs(node->left);
        int right = dfs(node->right);

        // second-layered info 
        int leftLeft = (node->left) ? dfs(node->left->left) : 0;
        int leftRight = (node->left) ? dfs(node->left->right) : 0;
        int rightLeft = (node->right) ? dfs(node->right->left) : 0;
        int rightRight = (node->right) ? dfs(node->right->right) : 0;

        // process this local node
        // if we take this node, 
        // we cannot take the left and right child,
        // but we can take the child of left and right
        int take = node->val + leftLeft+ leftRight + rightLeft + rightRight;
        int skip = left + right;

        memo[node] = max(take, skip);
        return max(take, skip);
    }
};