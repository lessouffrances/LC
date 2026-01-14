class Solution 
{
    public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) 
    {
        if (!root) return root;
        return dfs(root);

    }
    private:
    void dfs(TreeNode* node)
    {
        if (!node || !node->left) return node;
        TreeNode * newNode = dfs(node->left);

        node->left->left = node->right;
        node->left->right = node;

        node->left = nullptr;
        node->right = nullptr;

        return newNode;
    }
};