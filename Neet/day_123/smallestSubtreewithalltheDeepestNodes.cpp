class Solution 
{
    public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        return dfs(root)->first;
    }
    private:
    // postorder
    // each dfs contributes to the root and the height of that subtree
    pair<TreeNode*, int> dfs(TreeNode* node)
    {
        if (!node) return {nullptr, 0};

        auto [leftNode, leftDepth] = dfs(node->left);
        auto [rightNode, rightDepth] = dfs(node->right);

        if (leftDepth == rightDepth) return { node, leftDepth+1 }; // don't forget about the +1
        if (leftDepth > rightDepth) return { leftNode, leftDepth+1 };
        else return { rightNode, rightDepth+1 };
    }


    // ***** practice some relevent BT concepts here ******
    // Alert! getDepth is from top to bottom by concept, 
    // but depth is not a subtree property
    // we borrow height to solve depth.
    int getDepth(int val, TreeNode* root)
    {
        if (!root) return 0;

        return 1 + 
    }

    // postorder
    int getHeight(TreeNode* node)
    {
        if (!node) return 0;

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return 1 + max(leftHeight, rightHeight);
    }
};