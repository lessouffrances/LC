






class Solution 
{
    public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        if (!root) return nullptr;
        collectVals(root);
        int n = vals.size();
        return buildBalancedBST(0, n-1);
    }
    private:
    vector<int> vals;
    TreeNode* buildBalancedBST(int left, int right)
    {
        if (left > right) return nullptr;
        int mid = left + (right-left) / 2;
        int val = vals[mid];
        TreeNode* node = new TreeNode(val);
        node->left = buildBalancedBST(left, mid-1);
        node->right = buildBalancedBST(mid+1, right);
        return node;
    }
    void collectVals(TreeNode* node)
    {
        if (!node) return;
        collectVals(node->left);
        vals.push_back(node->val);
        collectVals(node->right);
    }
};
