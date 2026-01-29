class Solution 
{
    public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty()) return {};
    
        string startPath = "";
        dfs(digits, 0, startPath);
        return res;
    }
    private:
    vector<string> res;
    unordered_map<int, vector<char>> digitToChars = {
        {2, {'a', 'b', 'c'}},
        {3, {'d', 'e', 'f'}},
        {4, {'g', 'h', 'i'}},
        {5, {'j', 'k', 'l'}},
        {6, {'m', 'n', 'o'}},
        {7, {'p', 'q', 'r', 's'}},
        {8, {'t', 'u', 'v'}},
        {9, {'w', 'x', 'y', 'z'}}
    };

    void dfs(string& digits, int idx, string& currPath) 
    {
        if (idx == digits.length()) {
            res.push_back(currPath);
            return;
        }

        int digit = digits[idx] - '0';
        for (char ch : digitToChars[digit]) {
            currPath.push_back(ch);
            dfs(digits, idx+1, currPath);
            currPath.pop_back(); 
        }
    }
};