class Solution 
{
    public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        dfs(root);
        return diameter;
    }

    private:
    int diameter = 0;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        // 4 nodes, 3 edges, so 3 is the diameter, here no +1
        diameter = max(diameter, left+right);

        return 1+max(left, right);
    }
};