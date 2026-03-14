



// Time: O(N), each node was visited once
// Space: O(height of tree), recursion stack depth
class Solution 
{
    public:
    bool isValidBST(TreeNode* root) 
    {
        if (!root) return true;
        return validateBinarySearchTree(root, LONG_MIN, LONG_MAX);
    }
    private:
    // preorder
    bool validateBinarySearchTree(TreeNode* node, long minVal, long maxVal)
    {
        if (!node) return true;

        bool isLocalValid = node->val > minVal && node->val < maxVal;

        return isLocalValid 
        && validateBinarySearchTree(node->left, minVal, node->val)
        && validateBinarySearchTree(node->right, node->val, maxVal);
    }
};