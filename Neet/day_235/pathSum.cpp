class Solution 
{
    public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return dfs(root, 0, targetSum);
    }

    private:
    // pre-order, top-down
    bool dfs(TreeNode* node, int currSum, int targetSum)
    {
        if (!node) return false;
        currSum += node->val;
        
        if (!node->left && !node->right) {
            return currSum == targetSum;
        }
        return dfs(node->left, currSum, targetSum) 
        || dfs(node->right, currSum, targetSum);
    }
};