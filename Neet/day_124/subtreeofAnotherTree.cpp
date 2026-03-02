class Solution 
{
    public:
    // preorder
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        
        if (sameTree(root, subRoot)) return true;
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
    private:
    // preorder
    bool sameTree(TreeNode* root1, TreeNode* root2)
    {
        if (!root1 && !root2) return true;

        // root val equals
        if (root1 && root2 && root1->val == root2->val) {
            return sameTree(root1->left, root2->left)
            && sameTree(root1->right, root2->right);
        }
        return false;
    }
};