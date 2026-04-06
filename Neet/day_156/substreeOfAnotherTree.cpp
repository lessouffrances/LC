





class Solution 
{
    public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;

        if (isSame(root, subRoot)) return true;
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);

        return left || right;
    }
    private:
    bool isSame(TreeNode* root1, TreeNode* root2)
    {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;

        return root1->val == root2->val 
        && isSame(root1->left, root2->left) 
        && isSame(root1->right, root2->right);
    }
};