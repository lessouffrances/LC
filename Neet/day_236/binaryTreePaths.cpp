class Solution 
{
    public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string currPath = "";
        dfs(root, currPath);
        return res;
    }

    private:
    vector<string> res;

    void dfs(TreeNode* node, string& currPath)
    {
        if (!node) return;

        int len = currPath.size();
        if (currPath.empty()) {
            currPath += to_string(node->val);
        } else {
            currPath += "->";
            currPath += to_string(node->val);
        }

        if (!node->left && !node->right) {
            res.push_back(currPath);
        } else {
            dfs(node->left, currPath);
            dfs(node->right, currPath);
        }

        currPath.resize(len);
    }
};