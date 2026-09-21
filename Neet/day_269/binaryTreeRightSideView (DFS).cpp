class Solution 
{
    public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if (!root) return {};
        dfs(root, 0);
        return res;
    }
    private:
    unordered_set<int> seen;
    vector<int> res;
    void dfs(TreeNode* node, int row)
    {
        if (!node) return;

        if (!seen.count(row)) {
            res.push_back(node->val);
            seen.insert(row);
        }
        
        dfs(node->right, row+1);
        dfs(node->left, row+1);
    }
};