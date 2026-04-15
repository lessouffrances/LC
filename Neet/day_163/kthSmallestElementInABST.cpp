


class Solution 
{
    public:
    int kthSmallest(TreeNode* root, int k) 
    {
        if (!root) return 0;
        return dfs(root, k);
    }

    private:
    int dfs(TreeNode* node, int& k) {
        if (!node) return -1;

        int left = dfs(node->left, k);
        if (left != -1) return left;
        k -= 1;
        if (k == 0) return node->val;
        int right = dfs(node->right, k);
        if (right != -1) return right;
        return -1;
    }
};