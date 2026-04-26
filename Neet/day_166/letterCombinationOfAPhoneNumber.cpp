class Solution 
{
    public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits.length() == 0) return {};
        string currPath = "";
        dfs(digits, 0, currPath);
        return res;
    }

    private:
    vector<string> res;
    unordered_map<char, vector<char>> digitToChars = 
    {
        {'2', {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}}, 
        {'7', {'p','q','r','s'}},
        {'8', {'t','u','v'}}, 
        {'9', {'w','x','y','z'}}
    };

    void dfs(string digits, int currIdx, string currPath)
    {
        if (currIdx == digits.length()) {
            res.push_back(currPath);
            return;
        }

        // recurse
        for (auto& ch : digitToChars[digits[currIdx]]) {
            currPath.push_back(ch);
            dfs(digits, currIdx+1, currPath);
            currPath.pop_back();
        }
    }
};