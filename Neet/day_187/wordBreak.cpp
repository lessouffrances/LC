class Solution 
{
    public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        if (wordDict.empty()) return false;
        if (s.length() == 0) return false;

        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(0, s);
    }
    private:
    unordered_set<string> wordSet;
    unordered_map<int, bool> memo;

    bool dfs(int currIdx, const string& s)
    {
        if (currIdx == s.length()) return true;
        if (memo.count(currIdx)) return memo[currIdx];

        for (auto& word : wordSet) {
            // to see if the word can match the following chars
            int m = word.length();
            if (s.substr(currIdx, m) != word) continue;
            if (dfs(currIdx+m, s)) {
                memo[currIdx] = true;
                return true;
            }
        }
        memo[currIdx] = false;
        return false;
    }
};