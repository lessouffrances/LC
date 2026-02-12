



class Solution 
{
    public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        collectValsInorder(root);
        return preorderBuildBalancedBST(0, vals.size()-1);
    }
    private:
    vector<int> vals;
    void collectValsInorder(TreeNode* node)
    {
        if (!node) return;

        collectValsInorder(node->left);
        vals.push_back(node->val);
        collectValsInorder(node->right);
    }
    TreeNode* preorderBuildBalancedBST(int left, int right)
    {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(vals[mid]);

        node->left = preorderBuildBalancedBST(left, mid-1);
        node->right = preorderBuildBalancedBST(mid+1, right);

        return node;
    }
};