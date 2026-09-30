class Solution 
{
    public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        vector<TreeNode*> forest;
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        root = dfsProcessNode(root, toDelete, forest);
        if (root) forest.push_back(root);
        return forest;
    }

    private:
    // if this node was not deleted, contribute this entire subtree
    // if this node was deleted, append the forest and delete this node, contribute nullptr
    TreeNode* dfsProcessNode(TreeNode* node, unordered_set<int>& toDelete, vector<TreeNode*>& forest)
    {
        if (!node) return nullptr;

        node->left = dfsProcessNode(node->left, toDelete, forest);
        node->right = dfsProcessNode(node->right, toDelete, forest);

        if (toDelete.count(node->val)) {
            if (node->left) forest.push_back(node->left);
            if (node->right) forest.push_back(node->right);
            delete node;
            return nullptr;
        }
        return node;
    }
};