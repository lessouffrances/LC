class Solution 
{
    public:
    int longestConsecutive(TreeNode* root) 
    {
        if (!root) return 0;
        maxLen = 0;
        dfs(root, 0, false, 0);
        return maxLen;
    }

    private:
    int maxLen = 0;
    void dfs(TreeNode* node, int parentVal, bool hasParent, int currLen)
    {
        if (!node) return;

        bool isConsecutive = hasParent && (node->val - parentVal == 1);
        int newLen = isConsecutive ? currLen + 1 : 1;
        maxLen = max(maxLen, newLen);

        dfs(node->left, node->val, true, newLen);
        dfs(node->right, node->val, true, newLen);
    }
};