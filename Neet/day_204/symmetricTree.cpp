class Solution 
{
    public:
    bool isSymmetric(TreeNode* root) 
    {
        if (!root) return true;
        return isMirroed(root->left, root->right);
    }

    private:
    bool isMirroed(TreeNode* node1, TreeNode* node2)
    {
        if (!node1 && !node2) return true;
        if (!node1 || !node2) return false;

        bool isLocalOK = (node1->val == node2->val) ? true : false;
        return isLocalOK && isMirroed(node1->left, node2->right) 
        && isMirroed(node1->right, node2->left);
    }
};