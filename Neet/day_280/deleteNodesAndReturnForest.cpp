




class Solution 
{
    public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        root = dfs(root, toDelete);
        if (root) res.push_back(root);
        return res;
    }

    private:
    vector<TreeNode*> res;

    TreeNode* dfs(TreeNode* node, unordered_set<int> toDelete)
    {
        if (!node) return node;

        node->left = dfs(node->left, toDelete);
        node->right = dfs(node->right, toDelete);

        if (toDelete.count(node->val)) {
            if (node->left) res.push_back(node->left);
            if (node->right) res.push_back(node->right);
            delete node;
            return nullptr;
        } else {
            return node;
        }
    }
};