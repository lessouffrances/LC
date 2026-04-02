

// Time: O(N)
// Space: O(h), where h is the height of the tree

class Solution 
{
    public:
    int maxDepth(TreeNode* root) 
    {
        if (!root) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);
    }
};