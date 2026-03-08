


// Time: O (N * K^N), N for length of the input, and K for size of the adjLists

// Space: O(1) -> constant for the map
//        O(N * K^N) -> res stores K^N strings each of length n
//        O(N) -> dfs recurstion stack
//        currPath -> O(N)

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

    void dfs(int idx, string& currPath, const string& digits)
    {
        // base case
        if (idx == digits.length()) {
            res.push_back(currPath);
        }

        // recurse
        char currDigit = digits[idx];
        for (int digit : digitToChars[currDigit]) {
            currPath.push_back(digit);
            dfs(idx+1, currPath, digits);
            currPath.pop_back(); // backtrack
        }
    }
};