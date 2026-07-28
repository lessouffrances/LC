class Solution 
{
    public:
    int longestZigZag(TreeNode* root) 
    {
        dfs(root, -1, 0);
        return maxZigZagPathLen;
    }

    private:
    // return the longest zigzag path starting from this node left/right
    // with dir == -1, left
    // with dir == 1, right
    int maxZigZagPathLen = INT_MIN;

    void dfs(TreeNode* node, int dir, int steps)
    {
        if (!node) return;
        maxZigZagPathLen = max(maxZigZagPathLen, steps);

        if (dir == 1) {
            dfs(node->left, -1, steps+1);
            dfs(node->right, 1, 1);
        } else {
            dfs(node->left, -1, 1);
            dfs(node->right, 1, steps+1);
        }
    }
};