class Solution 
{
    public:
    int distributeCoins(TreeNode* root) 
    {
        if (!root) return 0;
        dfs(root);
        return move;
    }
    private:
    int move;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        int leftBal = dfs(node->left);
        int rightBal = dfs(node->right);

        move += abs(leftBal) + abs(rightBal);
        int bal = leftBal + rightBal + node->val - 1;
        return bal;
    }
};