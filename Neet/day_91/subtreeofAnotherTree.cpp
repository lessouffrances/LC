class Solution 
{
    public:
    // pre-order
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if (!subRoot) return true;
        if (!root) return false;

        if (sameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    private:
    // pre-order
    bool sameTree(TreeNode* root1, TreeNode* root2) 
    {
        if (!root1 && !root2) return true;
        
        if (root1 && root2 && root1->val == root2->val) {
            return sameTree(root1->left, root2->left) 
            && sameTree(root1->right, root2->right);
        }

        return false;
    }
};