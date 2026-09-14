class Solution 
{
    public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        return dfs(node1, node2);
    }

    private:
    // pre-order, top-down
    TreeNode* dfs(TreeNode* node1, TreeNode* node2)
    {
        if (!node1 && !node2) return null;
        
        int sum = 0;
        if (node1) sum += node1->val;
        if (node2) sum += node2->val;

        // create the node
        TreeNode* node = new TreeNode(sum);
        node->left = dfs(node1 ? node1->left : nullptr, node2 ? node2->left : nullptr);
        node->right = dfs(node1 ? node1->right : nullptr, node2 ? node2->right: nullptr);
        return node;
    }
};