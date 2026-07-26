class Solution 
{
    public:
    int findBottomLeftValue(TreeNode* root) 
    {
        if (!root) return -1;
        dfs(root, 0);
        return res;
    }
    
    private:
    int res;
    unordered_set<int> seen;

    void dfs(TreeNode* node, int depth)
    {
        if (!node) return;

        if (!seen.count(depth)) {
            res = node->val;
        }
        seen.insert(depth);

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};