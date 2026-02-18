



class Solution 
{
    public:
    bool isValidBST(TreeNode* root) 
    {
        if (!root) return true;
        return validate(root, LONG_MIN, LONG_MAX);
    }
    private:
    // preorder
    bool validate(TreeNode* node, long minVal, long maxVal)
    {
        if (!node) return true;

        bool isValid = node->val > minVal && node->val < maxVal;
        if (!isValid) return false;

        return isValid && 
        validate(node->left, minVal, node->val) 
        && validate(node->right, node->val, maxVal);
    }
};