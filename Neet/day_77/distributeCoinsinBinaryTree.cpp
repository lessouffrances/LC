class Solution {
    public:
    int distributeCoins(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return move;
    }
    private:
    // post order, bottom up 
    // return the node balance
    int move;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int leftBalance = dfs(node->left);
        int rightBalance = dfs(node->right);

        move += (abs(leftBalance) + abs(rightBalance));

        int balance = leftBalance + rightBalance + node->val - 1;
        return balance;
    }
};