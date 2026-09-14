class Solution 
{
    public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;

        // these 2 trees can be the same
        // or these 2 trees can be flippedly equal
        return ( (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) 
        || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left) ));
    }
};