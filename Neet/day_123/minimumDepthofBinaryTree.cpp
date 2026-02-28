
 
class Solution 
{
    public:
    //postorder
    // The minimum depth is defined as the path to the nearest leaf, 
    // and a node with one child is not a leaf 
    // — you must continue down the existing child.
    int minDepth(TreeNode* root) 
    {
        if (!root) return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (!root->left) return 1 + right;
        if (!root->right) return 1 + left;

        return 1 + min(left, right);
    }
};