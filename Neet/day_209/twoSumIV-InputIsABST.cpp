class Solution 
{
    public:
    bool findTarget(TreeNode* root, int k) 
    {
        if (!root) return false;
        return dfs(root, k);
    }

    private:
    unordered_set<int> seen;
    bool dfs(TreeNode* node, int k)
    {
        if (!node) return false;

        int diff = k-node->val;
        if (seen.count(diff)) return true;
        seen.insert(node->val);

        return dfs(node->left, k) || dfs(node->right, k);
    }
};