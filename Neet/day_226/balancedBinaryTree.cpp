class Solution 
{
    public:
    // preorder
    bool isBalanced(TreeNode* root) 
    {    
        if (!root) return true;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        bool isLocalBalanced = abs(leftHeight-rightHeight) <= 1;
        return isLocalBalanced && isBalanced(root->left) && isBalanced(root->right);
    }

    private:
    // postorder
    int getHeight(TreeNode* node)
    {
        if (!node) return 0;
        int left = getHeight(node->left);
        int right = getHeight(node->right);

        return 1+max(left, right);
    }
};