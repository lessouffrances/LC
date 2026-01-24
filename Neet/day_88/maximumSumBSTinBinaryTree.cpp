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
            // compute sum of this subtree and update global
            int sum = left.sum + right.sum + node->val;
            maxSum = max(maxSum, sum);

            return {true, min(node->val, left.minVal), max(node->val, right.maxVal), sum};
        } else {
            return {false, 0, 0, 0};
        }
    }
};
