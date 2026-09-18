class Solution 
{
    public:
    int pathSum(TreeNode* root, int targetSum) 
    {
        prefixSumCount[0] = 1;
        dfs(root, 0, targetSum);
        return res;
    }

    private:
    unordered_map<long long, int> prefixSumCount;
    int res = 0;
    void dfs(TreeNode* node, long long currSum, int targetSum) 
    {
        if (!node) return;

        currSum += node->val;
        res += prefixSumCount[currSum-targetSum];
        prefixSumCount[currSum]++;

        dfs(node->left, currSum, targetSum);
        dfs(node->right, currSum, targetSum);
        prefixSumCount[currSum]--;
    }
};