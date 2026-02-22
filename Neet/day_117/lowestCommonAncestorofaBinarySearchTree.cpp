class Solution 
{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root || root == q || root == p) return root;

        if (p->val > root->val && q->val > root->val) {
            // if both targets are on the right side of the tree
            return lowestCommonAncestor(root->right, p, q);
        } else if (p->val < root->val && q->val < root->val) {
            // if both targets are on the left side of the tree
            return lowestCommonAncestor(root->left, p, q);
        } else {
            // if they are on diff sides, the root of the subtree is the LCA
            return root;
        }
    }
};