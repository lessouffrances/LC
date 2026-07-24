class Solution 
{
    public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if (!root) return {};

        dfs(root);
        return res;
    }

    private:
    vector<int> res;
    void dfs(TreeNode* node) 
    {
        if (!node) return;

        dfs(node->left);
        res.push_back(node->val);
        dfs(node->right);
    }
};