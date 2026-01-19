class Solution 
{
    public:
    // preorder 
    int sumNumbers(TreeNode* root) 
    {
        if (!root) return 0;
        vector<int> startPath;
        dfs(root, startPath);

        int sum = 0;
        for (auto& path : res) {
            string currNum = "";
            for (int num : path) {
                currNum += to_string(num);
            }
            sum += stoi(currNum);
        }
        return sum;
    }

    private:
    vector<vector<int>> res;
    // pre-order
    void dfs(TreeNode* node, vector<int> currPath)
    {
        if (!node) return;

        if (!node->left && !node->right) {
            currPath.push_back(node->val);
            res.push_back(currPath);
            return;
        }

        currPath.push_back(node->val);
        dfs(node->left, currPath);
        dfs(node->right, currPath);
    }
};