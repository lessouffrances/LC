



class Solution 
{
    public:
    int goodNodes(TreeNode* root) 
    {
        if (!root) return 0;
        dfs(root, INT_MIN);
        return count;
    }
    private:
    // preorder
    int count = 0;
    void dfs(TreeNode* node, int ancestorMax)
    {
        if (!node) return;

        if (node->val >= ancestorMax) {
            count++;
            ancestorMax = node->val;
        }

        dfs(node->left, ancestorMax);
        dfs(node->right, ancestorMax);
    }
};