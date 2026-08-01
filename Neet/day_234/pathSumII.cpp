class Solution 
{
    public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> currPath = {};
        dfs(root, 0, currPath, targetSum);
        return res;
    }

    private:
    vector<vector<int>> res;
    void dfs(TreeNode* node, int currSum, vector<int>& currPath, int targetSum)
    {
        if (!node) return;

        int nextSum = currSum + node->val;
        currPath.push_back(node->val);

        if (!node->left && !node->right) {
            if (nextSum == targetSum) {
                res.push_back(currPath);
            }
        } else {
            dfs(node->left, nextSum, currPath, targetSum);
            dfs(node->right, nextSum, currPath, targetSum);
        }
        currPath.pop_back(); 
    }
};