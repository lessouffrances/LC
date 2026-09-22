



class Solution 
{
    public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        if (!root) return nullptr;
        return dfs(root, p);
    }

    private:
    TreeNode* prev = nullptr;
    // find p's successor
    // if prev = p, return node
    TreeNode* dfs(TreeNode* node, TreeNode* p)
    {
        if (!node) return nullptr;

        TreeNode* left = dfs(node->left, p);
        if (left) return left;

        if (prev == p) return node;
        prev = node;

        TreeNode* right = dfs(node->right, p);
        return right;
    }
};