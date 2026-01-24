struct Info
{
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};

class Solution 
{
    public:
    int maxSumBST(TreeNode* root)
    {
        if (!root) return 0;
        dfs(root);
        return maxSum;
    }
    private:
    int maxSum = 0;
    Info dfs(TreeNode* node)
    {
        if (!node) return {true, INT_MAX, INT_MIN, 0};

        Info left = dfs(node->left);
        Info right = dfs(node->right);

        bool isBST = left.isBST && right.isBST && node->val > left.maxVal && node->val < right.minVal;

        if (isBST) {
            int sum = left.sum + right.sum + node->val;
            maxSum = max(sum, maxSum);
            return { true, min(left.minVal, node->val), max(right.maxVal, node->val), sum };
        } else {
            return {false, 0, 0, 0};
        }
    }
};