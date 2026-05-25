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
    bool isSymmetric(TreeNode* root) 
    {
        if (!root) return true;
        return isMirrored(root->left, root->right);
    }
    private:
    // preorder
    bool isMirrored(TreeNode* node1, TreeNode* node2)
    {
        if (!node1 && !node2) return true;
        if (!node1 || !node2) return false;

        bool isLocalOK = node1->val == node2->val;

        return isLocalOK && isMirrored(node1->left, node2->right)
        && isMirrored(node1->right, node2->left);
    }
};