class Solution 
{
    public:
    int sumNumbers(TreeNode* root) 
    {
        if (!root) return 0;
        int currSum = 0;
        return dfs(root, currSum);
    }

    private:
    int dfs(TreeNode* node, int currSum) 
    {
        if (!node) return 0;

        if (!node->left && !node->right) {
            currSum = currSum * 10 + node->val;
            return currSum;
        } 
        currSum = currSum*10 + node->val;
        return dfs(node->left, currSum) + dfs(node->right, currSum);
    }
};