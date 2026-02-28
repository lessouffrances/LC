



class Solution 
{
    public:
    int kthSmallest(TreeNode* root, int k) 
    {
        if (!root) return 0;
        dfs(root, k);
        return res;
    }
    private:
    // inorder is the sorted sequence
    int res;
    void dfs(TreeNode* node, int& k) 
    {
        if (!node) return;
        dfs(node->left, k);

        // node
        k--;
        if (k == 0) {
            res = node->val;
            return;
        }
        dfs(node->right, k);
    }
};
