/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    unordered_map<string, int> seen;  // { serialization : count }
    vector<TreeNode*> res;
    string dfs(TreeNode* node) 
    {
        if (!node) return "#";
        string left = dfs(node->left);
        string right = dfs(node->right);
        string serialized = to_string(node->val) + "," + left + "," + right;
        if (seen[serialized] == 1) {
            res.push_back(node);
        }
        seen[serialized]++;
        return serialized;
    }
};