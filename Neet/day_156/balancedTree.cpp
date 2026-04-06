




class Solution 
{
    public:
    bool isBalanced(TreeNode* root) 
    {
        if (!root) return true;

        bool isLocalBalanced = abs(getHeight(root->left)-getHeight(root->right)) <= 1;
        return isLocalBalanced && isBalanced(root->left) && isBalanced(root->right);
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