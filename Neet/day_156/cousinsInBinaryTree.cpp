




class Solution 
{
    public:
    bool isCousins(TreeNode* root, int x, int y) 
    {
        if (!root) return false;

        return dfs(root, nullptr, 0, x).first == dfs(root, nullptr, 0, y).first
        && dfs(root, nullptr, 0, x).second != dfs(root, nullptr, 0, y).second;
    }

    private:
    // return the { depth, parent } of node in the tree
    // preorder 
    pair<int, TreeNode*> dfs(TreeNode* node, TreeNode* parent, int depth, int x)
    {
        if (!node) return { -1, nullptr };
        if (node->val == x) {
            return { depth, parent };
        } 

        auto left = dfs(node->left, node, depth+1, x);
        if (left.first != -1) return left;
        
        return dfs(node->right, node, depth+1, x);
    }
};