






class Solution 
{
    public:
    // preorder
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (!p && !q) return true;
        if (!p || !q) return false;

        bool isNodeSame = p->val == q->val;
        return isNodeSame && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};