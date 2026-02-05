




class Solution 
{
    public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (!p && !q) return true;
        if (!p || !q) return false;

        bool rootEqual = (p->val == q->val);
        return rootEqual && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};