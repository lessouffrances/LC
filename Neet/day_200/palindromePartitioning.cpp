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
            string subStr = s.substr(currIdx, i-currIdx+1);
            if (isPalindrome(subStr)) {
                currPath.push_back(subStr);
                dfs(i+1, currPath, s);
                currPath.pop_back(); // backtrack
            }
        }
    }

    bool isPalindrome(const string& s) 
    {
        int left = 0;
        int right = s.length()-1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};