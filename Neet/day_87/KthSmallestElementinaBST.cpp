class Solution 
{
    public:
    int kthSmallest(TreeNode* root, int k) 
    {
        idx = 0;
        dfs(root, k);
        return res;
    }
    private:
    // in-order
    int res;
    int idx;
    void dfs(TreeNode* node, int k)
    {
        if (!node) return;

        dfs(node->left, k);

        idx++;
        if (idx == k) {
            res = node->val;
            return;
        }
        
        dfs(node->right, k);
    }
};