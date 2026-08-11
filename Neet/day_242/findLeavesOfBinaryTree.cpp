class Solution 
{
    public:
    vector<vector<int>> findLeaves(TreeNode* root) 
    {
        if (!root) return {};
        dfs(root);

        vector<vector<int>> res;
        for (auto& [h, entry] : entries) {
            res.push_back(entry);
        }
        return res;
    }

    private:
    // post-order
    map<int, vector<int>> entries;
    int dfs(TreeNode* node)
    {
        if (!node) return -1;

        int leftHeight = dfs(node->left);
        int rightHeight = dfs(node->right);

        int currHeight = 1 + max(leftHeight, rightHeight);
        entries[currHeight].push_back(node->val);

        return currHeight;
    }
};