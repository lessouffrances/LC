




class Solution 
{
    public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        if (!root) return nullptr;

        collectValsInorder(root);
        int n = vals.size();
        return preorderBuildBalanacedBST(0, n-1);
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
    TreeNode* preorderBuildBalanacedBST(int left, int right)
    {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(vals[mid]);

        node->left = preorderBuildBalanacedBST(left, mid-1);
        node->right = preorderBuildBalanacedBST(mid+1, right);
        return node;
    }
};