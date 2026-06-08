class Solution 
{
    public:
    // BST property, all the vals at left side < node < vals at the right side
    // this can help us to effectively pick a side
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root) return nullptr;
        if (root == p || root == q) return root;

        // both p and q are at the left side of the current subtree
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }

    }
};