class Solution 
{
    public:
    int pathSum(TreeNode* root, int targetSum) 
    {
        prefixSumCount[0] = 1;
        dfs(root, 0, targetSum);
        return count;
    }

    private:
    int count = 0;
    unordered_map<long long, int> prefixSumCount;

    // preorder, top-down
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