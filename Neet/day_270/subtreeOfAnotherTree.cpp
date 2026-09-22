
class Solution 
{
    public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;

        if (isSameTree(root, subRoot)) return true;
        
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left || right;
    }

    private:
    bool isSameTree(TreeNode* node1, TreeNode* node2)
    {
        if (!node1 && !node2) return true;
        if (!node1 || !node2) return false;

        bool localEqual = node1->val == node2->val;
        return localEqual 
        && isSameTree(node1->left, node2->left) 
        && isSameTree(node1->right, node2->right);
    }
};