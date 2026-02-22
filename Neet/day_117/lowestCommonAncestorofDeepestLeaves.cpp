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
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        return dfs(root).first;
    }
    private:
    pair<TreeNode*, int> dfs(TreeNode* node)
    {
        if (!node) return { nullptr, -1 };

        auto [leftNode, leftHeight] = dfs(node->left);
        auto [rightNode, rightHeight] = dfs(node->right);

        if (leftHeight == rightHeight) return {node, leftHeight+1};
        if (leftHeight > rightHeight) return {leftNode, leftHeight+1};
        else return {rightNode, rightHeight+1}; 
    }
};