class Solution 
{
    public:
    int longestConsecutive(TreeNode* root) 
    {
        if (!root) return 0;
        dfs(root, INT_MIN, 0);
    }

    private:
    // pre-order
    int maxLen = INT_MIN;
    void dfs(TreeNode* node, long long parentVal, int currLen)
    {
        if (!node) return;

        int newLen = currLen;
        if (node->val - parentVal == 1) {
            newLen++;
        } else {
            newLen = 1;
        }
        maxLen = max(maxLen, newLen);

        dfs(node->left, node->val, newLen);
        dfs(node->right, node->val, newLen);
    }
};