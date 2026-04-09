
// Time: O(N * 2^N), for each pos, decide to cut or not
// Space: O(N)

class Solution 
{
    public:
    vector<vector<string>> partition(string s) 
    {
        if (s.length() == 0) return {};
        vector<string> currPath;
        dfs(0, currPath, s);
        return res;
    }

    private:
    vector<vector<string>> res;
    void dfs(int currIdx, vector<string>& currPath, const string& s) 
    {
        if (currIdx == s.length()) {
            res.push_back(currPath);
            return;
        }

        for (int i=currIdx; i<s.length(); i++) {
            string str = s.substr(currIdx, i-currIdx+1);
            if (isPalindrome(str)) {
                currPath.push_back(str);
                dfs(i+1, currPath, s);
                currPath.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s)
    {
        string copy = s;
        reverse(copy.begin(), copy.end());
        return copy == s;
    }
};