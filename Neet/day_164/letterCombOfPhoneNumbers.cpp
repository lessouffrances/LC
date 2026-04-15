class Solution 
{
    public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty()) return {};
        string currPath = "";
        dfs(0, currPath, digits);
        return res;
    }

    private:
    vector<string> res;
    unordered_map<char, vector<char>> digitToChars = {
        {'2', {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}},
        {'7', {'p','q','r','s'}},
        {'8', {'t','u','v'}},
        {'9', {'w','x','y','z'}}
    };

    void dfs(int currIdx, string currPath, const string& digits)
    {
        if (digits.empty()) return;

        if (currIdx == digits.size()) {
            res.push_back(currPath);
            return;
        }

        for (char letter : digitToChars[digits[currIdx]]) {
            currPath.push_back(letter);
            dfs(currIdx+1, currPath, digits);
            currPath.pop_back();
        }
    }
};