class Solution 
{
    public:
    int countUnivalSubtrees(TreeNode* root) 
    {
        dfs(root);
        return count;
    }

    private:
    // post-order
    // see if all the subtree down-up have the same value
    int count = 0;
    bool dfs(TreeNode* node)
    {
        if (!node) return true;

        bool leftUni = dfs(node->left);
        bool rightUni = dfs(node->right);
        bool isUni = leftUni && rightUni;
        if (isUni && node->left && node->left->val != node->val) isUni = false;
        if (isUni && node->right && node->right->val != node->val) isUni = false;

        if (isUni) count++;
        return isUni;
    }
};