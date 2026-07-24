class Solution 
{
    public:
    vector<int> rightSideView(TreeNode* root) 
    {    
        dfs(root, 0);
        return res;  
    }

    private:
    unordered_set<int> seen;
    vector<int> res;
    void dfs(TreeNode* node, int level) 
    {
        if (!node) return;

        if (!seen.count(level)) {
            res.push_back(node->val);
        }
        seen.insert(level);
        dfs(node->right, level+1);
        dfs(node->left, level+1);
    }
};