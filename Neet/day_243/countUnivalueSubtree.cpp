class Solution 
{
    public:
    int countUnivalSubtrees(TreeNode* root) 
    {
        if (!root) return 0;
        dfs(root);
        return count;
    }

    private:
    int count = 0;
    // bottom-up, post-order
    bool dfs(TreeNode* node)
    {
        if (!node) return true;

        bool isLeftUni = dfs(node->left);
        bool isRightUni = dfs(node->right);

        bool isLocalUni = isLeftUni && isRightUni;
        if (isLocalUni && node->left && node->val != node->left->val) isLocalUni = false;
        if (isLocalUni && node->right && node->val != node->right->val) isLocalUni = false;

        if (isLocalUni) count++;
        return isLocalUni;
    }
};