



class Solution 
{
    public:
    bool isSymmetric(TreeNode* root) 
    {
        if (!root) return true;    
        return isMirrored(root->left, root->right);
    }
    private:
    bool isMirrored(TreeNode* node1, TreeNode* node2) 
    {
        if (!node1 && !node2) return true;
        if (!node1 || !node2) return false;

        bool isLocalOk = node1->val == node2->val;

        return isLocalOk && isMirrored(node1->left, node2->right)
        && isMirrored(node1->right, node2->left);
    }
};