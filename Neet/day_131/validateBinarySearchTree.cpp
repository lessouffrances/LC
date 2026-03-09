


// Time: O(N), N is the number of nodes, each node was visited once. 
// Space: O(height of tree), which is the recursion stack depth.
class Solution 
{
    public:
    bool isValidBST(TreeNode* root) 
    {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
    private:
    // traversal order: preorder
    bool isValidBSTHelper(TreeNode* node, long minVal, long maxVal)
    {
        if (!node) return true;

        bool isLocalValid = node->val > minVal && node->val < maxVal;
        return isLocalValid 
        && isValidBSTHelper(node->left, minVal, node->val)
        && isValidBSTHelper(node->right, node->val, maxVal);
    }
};