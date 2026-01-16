class Solution 
{
    public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        if (wordDict.empty()) return false;

        vector<string> startPath; 
        return dfs(startPath, s, wordDict);
    }

    private:
    unordered_map<string, bool> memo;
    bool dfs(vector<string>& currPath, const string& s, vector<string>& wordDict)
    {
        string currStr = join(currPath);

        // check memo
        if (memo.count(currStr)) return memo[currStr];

        if (currStr == s) {
            return true;
        }

        if (s.find(currStr) != 0) {  // FIX: joined must be prefix of s
            return false;
        }

        // length exceeded
        if (currStr.length() >= s.length()) {
            return false;
        }
        
        for (auto& word : wordDict) {
            currPath.push_back(word);
            if (dfs(currPath, s, wordDict)) {
                memo[join(currPath)] = true;
                return true;
            }
            currPath.pop_back();
        }

        memo[currStr] = false;
        return false;
    }

    string join(vector<string>& words)
    {
        if (words.empty()) return "";

        string res = "";
        for (int i=0; i<words.size(); i++) {
            res += words[i];
        }
        return res;
    }
};