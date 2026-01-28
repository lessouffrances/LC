class Solution 
{
    public:
    void flatten(TreeNode* root) 
    {
        if (!root) return;
        flattenHelper(root);
    }
    private:
    TreeNode* flattenHelper(TreeNode* node) 
    {
        if (!node) return nullptr;

        TreeNode* oldRight = node->right;

        TreeNode* leftTail = flattenHelper(node->left);
        TreeNode* rightTail = flattenHelper(oldRight);

        if (node->left) {
            node->right = node->left;
            node->left = nullptr;

            if (leftTail) {
                leftTail->right = oldRight;
            }
        }

        if (rightTail) return rightTail;
        if (leftTail) return leftTail;
        return node;
    }
};