






// the sorting for this question is:
// lower row first and then lower val first

class Solution 
{
    public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if (!root) return {};

        queue<tuple<TreeNode*, int, int>> q; // { node, r, c }
        q.push( {root, 0, 0} );
        colToVals[0].push_back( {root->val, 0} );

        while (!q.empty()) {
            auto [node, r, c] = q.front();
            q.pop();

            if (node->left) {
                q.push( {node->left, r+1, c-1} );
                colToVals[c-1].push_back( {node->left->val, r+1} );
            } 
            if (node->right) {
                q.push( {node->right, r+1, c+1} );
                colToVals[c+1].push_back( {node->right->val, r+1} );
            }
        }

        vector<vector<int>> res;
        // sorting: lower row first, then lower value first
        for (auto& [ _, vals] : colToVals) {
            sort(vals.begin(), vals.end(), [](const auto& a, const auto& b){
                if (a.second != b.second) {
                    return a.second < b.second; // lower row first
                }
                return a.first < b.first; // lower val first
            });
            vector<int> subRes;
            for (auto& [val, row] : vals) {
                subRes.push_back(val);
            }
            res.push_back(subRes);
        }
        return res;
    }
    private:
    map<int, vector<pair<int, int>>> colToVals; // which sorts cols, col : { val, row }
};