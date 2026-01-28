class Solution 
{
    public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        if (s.length() == 0 || wordDict.empty()) return false;
        vector<string> startPath = {};
        return dfs(startPath, wordDict, s);
    }
    private:
    unordered_map<string, bool> memo;
    bool dfs(vector<string>& currPath, vector<string>& wordDict, const string& s)
    {
        string currStr = joined(currPath);
        if (memo.count(currStr)) return memo[currStr];

        if (currStr == s) {
            memo[currStr] = true;
            return true;
        }

        // prefix check
        if (s.find(currStr) != 0) {
            memo[currStr] = false;
            return false;
        }

        // length exceeds
        if (currStr.length() > s.length()) {
            memo[currStr] = false;
            return false;
        }

        for (auto& word : wordDict) {
            currPath.push_back(word);
            if (dfs(currPath, wordDict, s)) {
                memo[joined(currPath)] = true;
                return true;
            }
            currPath.pop_back();
        }

        memo[joined(currPath)] = false;
        return false;
    }

    string joined(vector<string>& path)
    {
        if (path.empty()) return "";
        int n = path.size();
        string res = "";
        for (int i=0; i<n; i++) {
            res += path[i];
        }
        return res;
    }
};