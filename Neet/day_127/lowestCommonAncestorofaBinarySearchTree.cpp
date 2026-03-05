class Solution 
{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root || root == p || root == q) return root;

        if (p->val > root->val && q->val > root->val) {
            // if both targets are greater than the root, go right
            return lowestCommonAncestor(root->right, p, q);
        } else if (p->val < root->val && q->val < root->val) {
            // if both targets are greater than the root, go left
            return lowestCommonAncestor(root->left, p, q);
        } else {
            // if p and q are on diff sides, the LCA is root
            return root;
        }
    }
};