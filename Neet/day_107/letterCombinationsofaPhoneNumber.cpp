class Solution 
{
    public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) return {};
        string startPath = "";
        dfs(0, startPath, digits);
        return res;
    }
    private:
    vector<string> res;
    unordered_map<int, vector<char>> digitToChars = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    void dfs(int idx, string& currPath, const string& digits)
    {
        if (idx == digits.length()) {
            res.push_back(currPath);
            return;
        }

        for (char ch : digitToChars[digits[idx]]) {
            currPath.push_back(ch);
            dfs(idx+1, currPath, digits);
            currPath.pop_back();
        }
    }
};