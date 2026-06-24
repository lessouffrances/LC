class Solution 
{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root) return nullptr;
        if (root == q || root == p) return root; 

        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
    }
};