/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    public:
    // pre-order traversal
    int widthOfBinaryTree(TreeNode* root) 
    {
        if (!root) return 0;
        dfs(root, 0, 1);
        return maxWidth;
    }

    private:
    unordered_map<int, long long> firstPos; // { level : the fristPos of that level }
    int maxWidth;
    void dfs(TreeNode* node, int level, long long pos)
    {
        if (!node) return;

        if (firstPos.find(level) == firstPos.end()) {
            firstPos[level] = pos;
        }

        long long normPos = pos - firstPos[level];
        maxWidth = max(maxWidth, (int)(pos - firstPos[level] + 1));
        dfs(node->left, level+1, 2*normPos+1);
        dfs(node->right, level+1, 2*normPos+2);
    }
};