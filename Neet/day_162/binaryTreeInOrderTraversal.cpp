

// Time: O(N)
// Space: O(N)
class Solution 
{
    public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if (!root) return {};
        dfs(root);
        return inorder;
    }

    private:
    vector<int> inorder;
    void dfs(TreeNode* node)
    {
        if (!node) return;

        dfs(node->left);
        inorder.push_back(node->val);
        dfs(node->right);
    }
};