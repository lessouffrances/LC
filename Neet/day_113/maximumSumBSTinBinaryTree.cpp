


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

        if (left.isBST && right.isBST 
        && node->val > left.maxVal && node->val < right.minVal) {
            int currSum = node->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum);
            return { true, min(node->val, left.minVal), max(node->val, right.maxVal), currSum };
        }

        return {false, 0, 0, 0};
    }
};