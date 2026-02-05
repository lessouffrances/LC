






class Solution 
{
    public:
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        if (!root) return {};

        queue<tuple<TreeNode*, int, int>> q; // node, row, col
        q.push( {root, 0, 0} );
        verticalVals[0].push_back(root->val);

        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto [node, row, col] = q.front();
                q.pop();

                if (node->left) {
                    q.push( {node->left, row+1, col-1} );
                    verticalVals[col-1].push_back(node->left->val);
                }
                if (node->right) {
                    q.push( {node->right, row+1, col+1} );
                    verticalVals[col+1].push_back(node->right->val);
                }
            }
        }

        vector<vector<int>> res;
        for (auto& [row, vals] : verticalVals) {
            res.push_back(vals);
        }
        
        return res;
    }
    private:
    map<int, vector<int>> verticalVals;
};