



// Time: O(N)
// Space: O(N)

class Solution 
{
    public:
    TreeNode* str2tree(string s) 
    {
        if (s.length() == 0) return nullptr;
        int idx = 0;
        return dfs(s, idx);
    }
    private:
    // preorder construct this binary tree
    TreeNode* dfs(const string& s, int& idx)
    {
        if (idx >= s.length()) return nullptr;
        int n = s.length();
        int start = idx;

        // detach this number
        while (idx < n && (isdigit(s[idx]) || s[idx] == '-')) {
            idx++;
        }
        int val = stoi(s.substr(start, idx));
        TreeNode* node = new TreeNode(val);

        // for the left child
        if (idx < n && s[idx] == '(') {
            idx++;
            node->left = dfs(s, idx);
            idx++;

        }
        // for the right child
        if (idx < n && s[idx] == '(') {
            idx++;
            node->right = dfs(s, idx);
            idx++;
        }
        return node;
    }
};