
class Solution 
{
    public:
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        dfs(root, 0, 0);

        vector<vector<int>> res;
        for (auto& [col, info] : colToRowValPairs) {
            stable_sort(info.begin(), info.end(), [](const auto& a, const auto& b){
                return a.first < b.first;
            });
            vector<int> vals;
            for (auto& [row, val] : info) {
                vals.push_back(val);
            }
            res.push_back(vals);
        }
        return res;
    }

    private:
    map<int, vector<pair<int, int>>> colToRowValPairs;
    void dfs(TreeNode* node, int row, int col)
    {
        if (!node) return;

        colToRowValPairs[col].push_back( {row, node->val} );

        dfs(node->left, row+1, col-1);
        dfs(node->right, row+1, col+1);
    }
};