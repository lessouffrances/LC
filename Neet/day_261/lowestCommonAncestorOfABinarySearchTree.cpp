class Solution 
{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root) return root;
        if (root == p || root == q) return root;

        if (root->val > p->val && root->val > q->val) {
            // go to left
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            return left;
        } else if (root->val < p->val && root->val < q->val) {
            // go to right
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            return right;
        } else {
            return root;
        }
    }
};