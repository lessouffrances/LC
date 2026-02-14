



class Solution 
{
    public:
    // preorder
    bool isBalanced(TreeNode* root) 
    {
        if (!root) return true;

        bool isNodeBalanced = abs(getHeight(root->left) - getHeight(root->right)) <= 1;
        return isNodeBalanced && isBalanced(root->left) && isBalanced(root->right);
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