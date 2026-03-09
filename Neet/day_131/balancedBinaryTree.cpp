class Solution 
{
    public:
    // preorder
    // abs (height(left subtree) - height(right subtree)) <= 1
    bool isBalanced(TreeNode* root) 
    {
        if (!root) return true;

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        bool isLocalBalanced = abs(left-right) <= 1;
        return isLocalBalanced 
        && isBalanced(root->left)
        && isBalanced(root->right);
    }
    private:
    // postorder
    int getHeight(TreeNode* node)
    {
        if (!node) return 0;

        int left = getHeight(node->left);
        int right = getHeight(node->right);

        return 1 + max(left, right);
    }
};