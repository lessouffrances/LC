class Solution 
{
    public:
    int distributeCoins(TreeNode* root) 
    {
        if (!root) return 0;
        dfs(root);
        return moves;    
    }

    private:
    int moves = 0;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int leftBal = dfs(node->left);
        int rightBal = dfs(node->right);

        moves += abs(leftBal)+abs(rightBal);
        int bal = leftBal+rightBal+node->val-1;

        return bal;
    }
};