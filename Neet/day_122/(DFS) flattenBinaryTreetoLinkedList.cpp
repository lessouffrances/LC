


class Solution 
{
    public:
    void flatten(TreeNode* root) 
    {
        if (!root) return;
        TreeNode* prev = nullptr;
        dfs(root, prev);
    }
    private:
    // why the prev is by-reference?
    // because the prev needs to be updated across all dfs calls
    // so, by-reference points to the address of prev,
    // and update the value in the address
    void dfs(TreeNode* node, TreeNode*& prev)
    {
        if (!node) return;

        TreeNode* left = node->left;
        TreeNode* right = node->right;

        if (prev) {
            prev->right = node;
            prev->left =  nullptr;
        }
        prev = node;

        dfs(left, prev);
        dfs(right, prev);
    }
};