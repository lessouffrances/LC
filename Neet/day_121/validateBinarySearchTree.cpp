



class Solution 
{
    public:
    bool isValidBST(TreeNode* root) 
    {
        if (!root) return true;
        return validate(root, LONG_MIN, LONG_MAX);
    }
    private:
    // subtree property: local validity
    // each node->val has to be > leftSubtree->minVal && < rightSubtree->maxVal
    // preorder
    bool validate(TreeNode* node, long minVal, long maxVal) 
    {
        if (!node) return true;

        bool isLocalValid = node->val > minVal && node->val < maxVal;
        if (!isLocalValid) return false;
        
        return isLocalValid 
        && validate(node->left, minVal, node->val)
        && validate(node->right, node->val, maxVal);
    }
};