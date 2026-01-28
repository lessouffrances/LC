class Solution 
{
    public:
    TreeNode* str2tree(string s) 
    {
        if (s.length() == 0) return nullptr;
        int start = 0;
        return dfs(s, start);
    }
    private:
    // pre-order
    TreeNode* dfs(const string& s, int& i) 
    {
        if (i > s.length()) return nullptr;
        int n = s.length();
        int start = i;

        // get the entire number with sign -
        string subStr = "";
        while (i < n && (isdigit(s[i]) || s[i] == '-')) {
            i++;
        }
        int val = stoi(s.substr(start, i-start));
        TreeNode* node = new TreeNode(val);

        if (i < n && s[i] == '(') {
            i++;
            node->left = dfs(s, i);
            i++;
        }

        if (i < n && s[i] == '(') {
            i++;
            node->right = dfs(s, i);
            i++;
        }

        return node;
    }
};