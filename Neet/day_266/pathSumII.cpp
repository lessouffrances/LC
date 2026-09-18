


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
        currSum += node->val;
        currPath.push_back(node->val);

        if (!node->left && !node->right) {
            if (currSum == targetSum) {
                res.push_back(currPath);
                return;
            }
        } else {
            dfs(node->left, currSum, currPath, targetSum);
            dfs(node->right, currSum, currPath, targetSum);
        }
        currPath.pop_back();
    }
};