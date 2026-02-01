





class Solution 
{
    public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if (!root) return {};

        queue<tuple<TreeNode*, int, int>> q; // treeNode, row, col
        q.push( {root, 0, 0} );

        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();

            lookUp[col].push_back( {row, node->val} );

            if (node->left) {
                q.push( {node->left, row+1, col-1} );
            }
            if (node->right) {
                q.push( {node->right, row+1, col+1} );
            }
        }

        vector<vector<int>> res;
        for (auto [col, nodes] : lookUp) {
            sort(nodes.begin(), nodes.end(), [](const auto& a, const auto& b) {
                if (a.first != b.first) {
                    return a.first < b.first;
                }
                return a.second < b.second;
            });
            vector<int> col;
            for (auto [row, val] : nodes) {
                col.push_back(val);
            }
            res.push_back(col);
        }

        return res;        
    }
    private:
    map<int, vector<pair<int, int>>> lookUp; // col, {row, val}
};