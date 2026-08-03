class Solution 
{
    public:
    string smallestFromLeaf(TreeNode* root) 
    {
        vector<char> currPath = {};
        dfs(root, currPath);
        return res;
    }

    private:
    string res = "";
    void dfs(TreeNode* node, vector<char>& currPath)
    {
        if (!node) return;
        char ch = 'a' + node->val;
        currPath.push_back(ch);

        if (!node->left && !node->right) {
            string currRes = string(currPath.rbegin(), currPath.rend());
            if (!res.empty() && currRes < res) {
                res = currRes;
            } else if (res.empty()) {
                res = currRes;
            }
        } else {
            dfs(node->left, currPath);
            dfs(node->right, currPath);
        }
        currPath.pop_back(); // backtrack
    }
};