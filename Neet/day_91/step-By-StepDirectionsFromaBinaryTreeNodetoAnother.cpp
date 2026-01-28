class Solution 
{
    public:
    string getDirections(TreeNode* root, int startValue, int destValue)
    {
        if (!root) return "";

        TreeNode* lca = findLCA(root, startValue, destValue);
        // from lca to startValue
        string oneHalf = "";
        dfs(lca, startValue, oneHalf);

        // from lca to destValue
        string secondHalf = "";
        dfs(lca, destValue, secondHalf);

        // need to reverse the oneHalf
        string reversed = string(oneHalf.length(), 'U');
        return reversed + secondHalf;
    }
    private:
    // pre-order to find a val from top
    // the string is from top to bottom
    bool dfs(TreeNode* node, int val, string& path)
    {
        if (!node) return false;

        if (node->val == val) return true;

        path.push_back('L');
        if (dfs(node->left, val, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (dfs(node->right, val, path)) return true;
        path.pop_back();

        return false;
    }

    TreeNode* findLCA(TreeNode* node, int q, int p)
    {
        if (!node || node->val == p || node->val == q) return node;
        TreeNode* left = findLCA(node->left, q, p);
        TreeNode* right = findLCA(node->right, q, p);
        
        if (left && right) return node;
        return left ? left : right;
    }
};