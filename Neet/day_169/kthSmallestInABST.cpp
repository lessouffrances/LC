class Solution 
{
    public:
    int kthSmallest(TreeNode* root, int k) 
    {
        if (!root) return -1;
        dfs(root, k);
        return res;
    }

    private:
    int res;
    void dfs(TreeNode* node, int& k)
    {
        if (!node) return;

        dfs(node->left, k);
        k -= 1;
        if (k == 0) {
            res = node->val;
            return;
        }
        dfs(node->right, k);
    }
};