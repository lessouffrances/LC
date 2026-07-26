class Solution 
{
    public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if (!root) return {};
        map<int, vector<pair<int, int>>> colToVals; // {row, val}
        queue<tuple<TreeNode*, int, int>> q; // node, row, col
        q.push( {root, 0, 0} );

        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();
            colToVals[col].push_back( {row, node->val} );
            if (node->left) {
                q.push( {node->left, row+1, col-1} );
            }
            if (node->right) {
                q.push( {node->right, row+1, col+1} );
            }
        }

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
};
