class Solution 
{
    public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if (!root) return {};
        dfs(root, 0, 0);

        vector<vector<int>> res;
        for (auto& [_,  rowValPairs] : valsByCol) {
            // sort by row
            sort(rowValPairs.begin(), rowValPairs.end());
            vector<int> group;
            for (auto& [_, val] : rowValPairs) {
                group.push_back(val);
            }
            res.push_back(group);
        }
        return res;
    }

    private:
    // map is sorted by key
    map<int, vector<pair<int, int>>> valsByCol;

    void dfs(TreeNode* node, int row, int col)
    {
        if (!node) return;

        valsByCol[col].push_back( {row, node->val} );

        if (node->left) {
            dfs(node->left, row+1, col-1);
        }
        if (node->right) {
            dfs(node->right, row+1, col+1);
        }
    }
};