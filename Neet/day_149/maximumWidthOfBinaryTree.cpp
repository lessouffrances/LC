
// Time: O(N)
// Space: O(h)
class Solution 
{
    public:
    
    int widthOfBinaryTree(TreeNode* root) 
    {
        if (!root) return 0;
        dfs(root, 0, 0);
        return maxWidth;
    }
    private:
    int maxWidth = 0;
    unordered_map<int, int> firstPos; // { level, firstPos }

    // pre-order traversal
    void dfs(TreeNode* node, int level, int pos) 
    {
        if (!node) return;

        if (!firstPos.count(level)) {
            firstPos[level] = pos;
        }

        long long normPos = pos - firstPos[level];
        maxWidth = max(maxWidth, (int)pos-firstPos[level]+1);
        dfs(node->left, level+1, 2*normPos);
        dfs(node->right, level+1, 2*normPos+1);
    }
};