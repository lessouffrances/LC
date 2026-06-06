class Solution 
{
    public:
    bool findTarget(TreeNode* root, int k) 
    {
        return dfs(root, k);
    }

    private:
    unordered_map<int, int> valToCount;
    // preorder
    bool dfs(TreeNode* node, int k)
    {
        if (!node) return false;

        if (valToCount.count(k-node->val)) return true;
        valToCount[node->val]++;

        return dfs(node->left, k) || dfs(node->right, k);
    }
};