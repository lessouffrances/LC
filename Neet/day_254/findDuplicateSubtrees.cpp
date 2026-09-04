// subtree, the identity can be encoded as strings

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
    // bottom-up, post-order
    string dfs(TreeNode* node) 
    {
        if (!node) return "";
        string left = dfs(node->left);
        string right = dfs(node->right);
        string localSubtree = left + "->" + right + "->" + to_string(node->val);
        if (freq[localSubtree] == 1) res.push_back(node);
        
        freq[localSubtree]++;
        return localSubtree;
    }
};