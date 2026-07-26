class Solution 
{
    public:
    vector<int> largestValues(TreeNode* root) 
    {
        if (!root) return {};
        dfs(root, 0);
        return res;
    }

    private:
    vector<int> res;
    void dfs(TreeNode* node, int depth)
    {
        if (!node) return;

        // this is because we didn't allocate space for res
        // and we cannot do that initially
        if (depth == res.size()) {
            res.push_back(node->val);
        } else {
            res[depth] = max(res[depth], node->val);
        }

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};