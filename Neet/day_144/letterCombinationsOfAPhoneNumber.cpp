class Solution 
{
    public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0) return {};

        string currPath = "";
        dfs(0, currPath, digits);
        return res;
    }
    private:
    unordered_map<char, vector<char>> digitToChars = 
    {
        {'2', {'a', 'b', 'c'} },
        {'3', {'d', 'e', 'f'} },
        {'4', {'g', 'h', 'i'} },
        {'5', {'j', 'k', 'l'} },
        {'6', {'m', 'n', 'o'} },
        {'7', {'p', 'q', 'r', 's' } },
        {'8', {'t', 'u', 'v'} },
        {'9', {'w', 'x', 'y', 'z'} }
    };

    vector<string> res;
    void dfs(int currIdx, string& currPath, const string& digits) 
    {
        if (currIdx == digits.length()) {
            res.push_back(currPath);
            return;
        }

        char currDigit = digits[currIdx];
        for (int digit : digitToChars[currDigit]) {
            currPath.push_back(digit);
            dfs(currIdx+1, currPath, digits);
            currPath.pop_back();
        }
    }
};