class Solution 
{
    public:
    string getDirections(TreeNode* root, int startValue, int destValue)
    {
        if (!root) return "";

        // the lca is the turining point for the path
        TreeNode* lca = findLCA(root, startValue, destValue);

        // from lca to startValue
        string firstHalf = "";
        dfs(lca, startValue, firstHalf);

        // from lca to startValue
        string secondHalf = "";
        dfs(lca, destValue, secondHalf);

        // change all in firstHalf into 'U'
        firstHalf = string(firstHalf.length(), 'U');
        return firstHalf + secondHalf;
    }
    private:
    // preorder to find a val from the top
    bool dfs(TreeNode* node, int val, string& path)
    {
        if (!node) return false;
        if (node->val == val) return true;

        // go left
        path.push_back('L');
        if (dfs(node->left, val, path)) return true; // we need this return to stop the pop next line
        path.pop_back();
        
        // go right
        path.push_back('R');
        if (dfs(node->right, val, path)) return true; 
        path.pop_back();

        return false;
    }
    //postorder
    TreeNode* findLCA(TreeNode* node, int p, int q)
    {
        if (!node || node->val == q || node->val == p) return node;

        TreeNode* left = findLCA(node->left, p, q);
        TreeNode* right = findLCA(node->right, p, q);

        if (left && right) return node;
        return left ? left : right;
    }
};