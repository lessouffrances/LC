class Solution 
{
    public:
    bool isValidBST(TreeNode* root) 
    {
        if (!root) return true;
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    private:
    // preorder, top-donwn
    bool dfs(TreeNode* node, long minVal, long maxVal)
    {
        if (!node) return true;

        bool isLocalOK = node->val > minVal && node->val < maxVal;
        return isLocalOK 
        && dfs(node->left, minVal, node->val) 
        && dfs(node->right, node->val, maxVal);
    }
};