class Solution 
{
    // one move: move one coin thru one edge
    public:
    int distributeCoins(TreeNode* root) 
    {
        if (!root) return 0;
        dfs(root);
        return totalMoves;
    }
    private:
    int totalMoves = 0;
    // bottom-up, post-order
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int leftBal = dfs(node->left);
        int rightBal = dfs(node->right);

        totalMoves += abs(leftBal) + abs(rightBal);
        int localBal = leftBal + rightBal + node->val - 1;
        return localBal;
    }
};