class Solution 
{
    public:
    int longestConsecutive(TreeNode* root) 
    { 
        if (!root) return 0;
        dfs(root, INT_MIN, 0);
        return maxLen;
    }

    private:
    // pre-order
    int maxLen = 0;
    void dfs(TreeNode* node, long long parentVal, int currLen)
    {
        if (!node) return;

        if (node->val == parentVal + 1) currLen++;
        else currLen = 1;
        maxLen = max(maxLen, currLen);

        dfs(node->left, node->val, currLen);
        dfs(node->right, node->val, currLen);
    }
};