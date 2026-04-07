


class Solution 
{
    public:
    string getDirections(TreeNode* root, int startValue, int destValue)
    {
        if (!root) return "";

        TreeNode* lca = getLCA(root, startValue, destValue);
        string firstHalf = "";
        dfs(lca, startValue, firstHalf);
        
        string secondHalf = "";
        dfs(lca, destValue, secondHalf);

        // change all char in firstHalf path into 'U'
        firstHalf = string(firstHalf.length(), 'U');
        return firstHalf + secondHalf;
    }

    private:
    // preorder to find the path from lca to the node
    bool dfs(TreeNode* node, int target, string& currPath)
    {
        if (!node) return "";
        if (node->val == target) return true;

        // go left 
        currPath.push_back('L');
        if (dfs(node->left, target, currPath)) return true; 
        currPath.pop_back();

        // go right
        currPath.push_back('R');
        if (dfs(node->right, target, currPath)) return true;
        currPath.pop_back();

        return false;
    }

    TreeNode* getLCA(TreeNode* node, int p, int q)
    {
        if (!node || node->val == p || node->val == q) return node;

        TreeNode* left = getLCA(node->left, p, q);
        TreeNode* right = getLCA(node->right, p, q);

        if (left && right) return node;
        return left ? left : right;
    }
};