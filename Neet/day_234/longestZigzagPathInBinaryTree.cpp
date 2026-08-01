class Solution 
{
    public:
    int longestZigZag(TreeNode* root) 
    {
        dfs(root, true, 0);
        return maxZigZag;
    }
    private:
    int maxZigZag = INT_MIN;
    // preorder
    void dfs(TreeNode* node, bool wasLeft, int len)
    {
        if (!node) return;
        maxZigZag = max(len, maxZigZag);
        
        if (wasLeft) {
            // if increment, has to go right
            dfs(node->right, false, len+1);
            // not increment, could go left
            dfs(node->left, true, 1);
        } else {
            // if increment, has to go left
            dfs(node->left, true, len+1);
            // not increment, could go right
            dfs(node->right, false, 1);
        }
    }
};