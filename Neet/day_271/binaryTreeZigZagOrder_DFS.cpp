




class Solution 
{
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if (!root) return {};

        dfs(root, 0);
        vector<vector<int>> res;
        for (auto& [row, vals] : rowToVals) {
            if (row % 2 != 0) {
                reverse(vals.begin(), vals.end());
            }
            res.push_back(vals);
        }
        return res;
    }

    private:
    map<int, vector<int>> rowToVals;

    void dfs(TreeNode* node, int row)
    {
        if (!node) return;

        rowToVals[row].push_back(node->val);
        dfs(node->left, row+1);
        dfs(node->right, row+1);
    }
};