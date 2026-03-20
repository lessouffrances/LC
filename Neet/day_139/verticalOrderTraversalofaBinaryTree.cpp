


// Time: O(N log N)
// - BFS visits each node once: O(N)
// - Inserting into `map` is O(log N) per node: O(n log n)
// - Sorting each column's values: O(N log N) total across all columns

// Space: O(N)
// - BFS queue holds at most O(N) nodes
// - `colToVals` stores all n nodes across all columns: O(N)

class Solution 
{
    public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if (!root) return {};

        queue<tuple<TreeNode*, int, int>> q;
        q.push( {root, 0, 0} ); // node, 
        colToVals[0].push_back( { root->val, 0 } );

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
        for (auto& [ _, vals] : colToVals) {
            // sort each col based on row first then val
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
    map<int, vector<pair<int, int>>> colToVals; // { col : {val, row} }
}; 