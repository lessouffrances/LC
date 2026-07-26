class Solution 
{
    public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if (!root) return {};
        dfs(root, 0, 0);
        vector<vector<int>> res;

        for (auto& [_, vals] : colToVals) {
            sort(vals.begin(), vals.end());
            vector<int> v;
            for (auto& p : vals) {
                v.push_back(p.second);
            }
            res.push_back(v);
        }
        return res;
    }

    private:
    map<int, vector<pair<int, int>>> colToVals;
    void dfs(TreeNode* node, int row, int col)
    {
        if (!node) return;
        colToVals[col].push_back( {row, node->val} );
        if (node->left) dfs(node->left, row+1, col-1);
        if (node->right) dfs(node->right, row+1, col+1);
    }
};
