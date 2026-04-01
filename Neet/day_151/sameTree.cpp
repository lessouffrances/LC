

// Time: O(N), N is the total number of nodes
// Space: O(1), 

class Solution 
{
    public:
    // preorder
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (!p && !q) return true;
        if (!p || !q) return false;

        return p->val == q->val
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
    }
};