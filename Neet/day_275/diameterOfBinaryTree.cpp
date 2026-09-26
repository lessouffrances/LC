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
    
    // return the maximum path including this node downwards
    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        diameter = max(left+right, diameter);
        return 1+max(left, right);
    }
};