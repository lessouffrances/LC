class Solution 
{
    public:
    bool isBalanced(TreeNode* root) 
    {
        return dfs(root) != -1;
    }

    private:
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int leftDepth = dfs(node->left);
        if (leftDepth == -1) return -1;
        int rightDepth = dfs(node->right);
        if (rightDepth == -1) return -1;

        bool isLocalBalanced = abs(rightDepth-leftDepth) <= 1;
        if (!isLocalBalanced) return -1;
    
        return max(leftDepth, rightDepth)+1;
    }
};