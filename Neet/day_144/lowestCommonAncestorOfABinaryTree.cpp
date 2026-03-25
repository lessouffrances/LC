// Time: O(n) — visits every node once in the worst case.
// Space: O(h) — recursion stack depth equals the tree height; 
// O(log n) for a balanced tree, O(n) worst case for a skewed tree.

class Solution 
{
    public:
    // postorder
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }
};