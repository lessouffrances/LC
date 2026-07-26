class Solution 
{
    public:
    vector<int> leftSideView(TreeNode* root) 
    {
        if (!root) return {};
        dfs(root, 0);
        return res;
    }

    private:
    vector<int> res;
    unordered_set<int> seen;

    void dfs(TreeNode* node, int level) 
    {
        if (!node) return;

        if (!seen.count(level)) {
            res.emplace_back(node->val);
        }
        seen.insert(level);

        dfs(node->left, level+1);
        dfs(node->right, level+1);
    }
};