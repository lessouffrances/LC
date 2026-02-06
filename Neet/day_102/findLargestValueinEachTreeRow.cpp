







class Solution 
{
    public:
    vector<int> largestValues(TreeNode* root) 
    {
        if (!root) return {};

        map<int, vector<int>> rowToVals;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0}); // node, row 
        rowToVals[0].push_back(root->val);
        
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto [node, row] = q.front();
                q.pop();

                if (node->left) {
                    q.push({node->left, row+1});
                    rowToVals[row+1].push_back(node->left->val);
                }
                if (node->right) {
                    q.push({node->right, row+1});
                    rowToVals[row+1].push_back(node->right->val);
                }
            }
        }

        vector<int> ans;
        for (auto& [row, vals] : rowToVals) {
            ans.push_back(*max_element(vals.begin(), vals.end()));
        }
        return ans;
    }
};