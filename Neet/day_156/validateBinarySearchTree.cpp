





class Solution 
{
    public:
    bool isValidBST(TreeNode* root) 
    {
        if (!root) return true;
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    private:
    bool dfs(TreeNode* node, long minVal, long maxVal)
    {
        if (!node) return true;

        bool isLocalValid = node->val > minVal && node->val < maxVal;
        return isLocalValid
        && dfs(node->left, minVal, node->val) 
        && dfs(node->right, node->val, maxVal);
    }
};