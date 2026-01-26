class Solution 
{
    public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if (!root) return {};

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push( {root, {0, 0} } );
        
        while (!q.empty()) {
            auto [node, pos] = q.front();
            int r = pos.first;
            int c = pos.second;
            q.pop();

            map[c].push_back( {node, r} );

            if (node->left) {
                q.push( {node->left, {r+1, c-1}});
            }
            if (node->right) {
                q.push( {node->right, {r+1, c+1}});
            }
        }

        vector<vector<int>> res;
        for (auto& [c, vec] : map) {
            sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){
                if (a.second != b.second) {
                    return a.second < b.second;
                } 
                return a.first->val < b.first->val;
            }); 

            vector<int> col;
            for (auto& [node, r] : vec) {
                col.push_back(node->val);
            }
            res.push_back(col);
        }
        return res;
    }
    private:
    map<int, vector<pair<TreeNode*, int>>> map; // {col, {node, row}}
};