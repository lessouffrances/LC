
class Solution 
{
    public:
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        if (!root) return {};
        map<int, vector<int>> colToVals;

        queue<pair<TreeNode*, int>> q; // { node, col }
        q.push( {root, 0} );
        
        while (!q.empty()) {
            auto [currNode, col] = q.front(); q.pop();
            colToVals[col].push_back(currNode->val);

            if (currNode->left) q.push( {currNode->left, col-1} );
            if (currNode->right) q.push( {currNode->right, col+1});
        }

        vector<vector<int>> res;
        for (auto& [_, vals] : colToVals) {
            res.push_back(vals);
        }
        return res;
    }
};