class Solution 
{
    public:
    int goodNodes(TreeNode* root) 
    {
        dfs(root, INT_MIN);
        return count;
    }

    private:
    int count = 0;
    // pre-order
    void dfs(TreeNode* node, int ancestorMax)
    {
        if (!node) return;

        if (node->val >= ancestorMax) {
            ancestorMax = node->val;
            count++;
        }

        dfs(node->left, ancestorMax);
        dfs(node->right, ancestorMax);
    }
};