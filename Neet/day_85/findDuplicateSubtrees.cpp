class Solution 
{
    public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        if (!root) return {};
        dfs(root);
        return res;
    }
    private:
    vector<TreeNode*> res;
    unordered_map<string, int> freq;
    string dfs(TreeNode* node) 
    {
        if (!node) return "";

        string left = dfs(node->left);
        string right = dfs(node->right);
        string serialized = to_string(node->val) + "<" + left + "<" + right;

        if (freq[serialized] == 1) {
            res.push_back(node);
        }

        freq[serialized]++;
        return serialized;
    }
};