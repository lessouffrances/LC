









class Solution 
{
    public:
    //preorder
    bool isBalanced(TreeNode* root) 
    {
        if (!root) return true;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        bool isRootBalanced = abs(leftHeight-rightHeight) <= 1;

        return isRootBalanced && isBalanced(root->left) && isBalanced(root->right);
    }
    private:
    //postorder
    int getHeight(TreeNode* node) 
    {
        if (!node) return 0;

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return 1 + max(leftHeight, rightHeight);
    }
};