


class Solution 
{
    public:
    string tree2str(TreeNode* root) 
    {
        if (!root) return "";
        return dfs(root);
    }
    private:
    string dfs(TreeNode* node)
    {
        if (!node) return "";

        string res = to_string(node->val);
        if (!node->left && !node->right) return res;
        
        res = res + '(' + dfs(node->left) + ')';
        if (node->right) {
            res = res + '(' + dfs(node->right) + ')';
        }
    
        return res;
    }
};