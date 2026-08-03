class Solution 
{
    public:
    int pathSum(TreeNode* root, int targetSum) 
    {
        // seed
        prefixSumCount[0] = 1;
        dfs(root, 0, targetSum);
        return count;
    }

    private:
    unordered_map<long long, int> prefixSumCount; 
    int count = 0;
    void dfs(TreeNode* node, long long currSum, int targetSum)
    {
        if (!node) return;

        currSum += node->val;
        count += prefixSumCount[currSum-targetSum];
        prefixSumCount[currSum]++;

        // recurse
        dfs(node->left, currSum, targetSum);
        dfs(node->right, currSum, targetSum);
        prefixSumCount[currSum]--; // backtrack
    }
};