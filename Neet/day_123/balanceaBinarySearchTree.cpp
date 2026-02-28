



class Solution 
{
    public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        if (!root) return nullptr;

        // collect vals
        dfs(node);
        int left = 0, right = vals.size()-1;
        return buildBalancedBST(left, right);
    }
    private:
    // use inorder to preserve the sequence
    vector<int> vals;
    void dfs(TreeNode* node) 
    {
        if (!node) return nullptr;

        dfs(node->left);
        vals.push_back(node->val);
        dfs(node->right);
    }

    // preorder
    TreeNode* buildBalancedBST(int left, int right)
    {
        if (left > right) return nullptr;

        int mid = left + (right-left)/2;
        int rootVal = vals[mid];

        TreeNode* node = new TreeNode(rootVal);
        node->left = buildBalancedBST(left, mid-1);
        node->right = buildBalancedBST(mid+1, right);

        return node;
    }
};