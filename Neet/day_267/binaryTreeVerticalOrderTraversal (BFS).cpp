

class Solution 
{
    public:
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        if (!root) return {};
        map<int, vector<int>> colToVals;
        queue<pair<TreeNode*, int>> q; // {val, col}
        q.push( {root, 0} );
        
        while (!q.empty()) {
            auto [node, col] = q.front(); q.pop();
            colToVals[col].push_back(node->val);

            if (node->left) {
                q.push( {node->left, col-1} );
            }
            if (node->right) {
                q.push( {node->right, col+1} );
            }
        }

        vector<vector<int>> res;
        for (auto& [col, vals] : colToVals) {
            res.push_back(vals);
        }
        return res;
    }
};