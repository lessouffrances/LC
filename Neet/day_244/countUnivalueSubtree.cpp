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
    // post-order
    int count = 0;
    // return if this node->val equals the left->val and right->val
    bool dfs(TreeNode* node)
    {
        if (!node) return true;

        bool isLeftUni = dfs(node->left);
        bool isRightUni = dfs(node->right);

        bool isLocalUni = isLeftUni && isRightUni;
        if (isLocalUni && node->left && node->left->val != node->val) isLocalUni = false;
        if (isLocalUni && node->right && node->right->val != node->val) isLocalUni = false;
        if (isLocalUni) count++;
        return isLocalUni;
    }
};