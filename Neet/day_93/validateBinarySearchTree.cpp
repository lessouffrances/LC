class Solution 
{
    public:
    bool isValidBST(TreeNode* root) 
    {
        if (!root) return true;

        return validate(root, LONG_MAX, LONG_MIN);

    }
    private:
    bool validate(TreeNode* node, long maxVal, long minVal) 
    {
        if (!node) return true;

        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        return validate(node->left, node->val, minVal)
               && validate(node->right, maxVal, node->val);
    }
};