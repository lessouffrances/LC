




class Solution 
{
    public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if (!root) return {};

        dfs(root);
        return vals;
    }
    private:
    vector<int> vals;
    void dfs(TreeNode* node)
    {
        if (!node) return;

        dfs(node->left);
        vals.push_back(node->val);
        dfs(node->right);
    }
};