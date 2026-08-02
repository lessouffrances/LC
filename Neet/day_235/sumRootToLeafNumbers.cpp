class Solution 
{
    public:
    int sumNumbers(TreeNode* root) 
    {
        return dfs(root, 0);
    }

    private:
    int dfs(TreeNode* node, int currSum)
    {
        if (!node) return 0;
        currSum = currSum*10 + node->val;

        if (!node->left && !node->right) {
            return currSum;
        } 
        return dfs(node->left, currSum) + dfs(node->right, currSum);
    }
};