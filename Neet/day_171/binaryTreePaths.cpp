

class Solution 
{
    public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if (!root) return {};
        string currPath = "";
        dfs(root, currPath);
        return res;
    }

    private:
    vector<string> res;
    void dfs(TreeNode* node, string currPath)
    {
        if (!node) return;
        currPath += to_string(node->val);
        if (!node->left && !node->right) {
            res.push_back(currPath);
            return;
        }

        currPath += "->";
        dfs(node->left, currPath);
        dfs(node->right, currPath);
    }
};
