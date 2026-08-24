class Solution 
{
    public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if (!root) return {};
        
        queue<tuple<TreeNode*, int, int>> q; // {node, row, col}
        q.push( {root, 0, 0} );
        map<int, vector<pair<int, int>>> valsByCol;

        while (!q.empty())
        {
            auto [node, row, col] = q.front();
            q.pop();
            valsByCol[col].push_back( {row, node->val} );

            if (node->left) {
                q.push( {node->left, row+1, col-1} );
            }
            if (node->right) {
                q.push( {node->right, row+1, col+1} );
            }
        }

        vector<vector<int>> res;
        for (auto& [_, rowValPairs] : valsByCol) {
            sort(rowValPairs.begin(), rowValPairs.end());
            vector<int> group;
            for (auto& [_, val] : rowValPairs) {
                group.push_back(val);
            }
            res.push_back(group);
        }
        return res;
    }
};