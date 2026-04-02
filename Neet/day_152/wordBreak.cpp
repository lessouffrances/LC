






class Solution 
{
    public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        if (s.length() == 0) return true;

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return dfs(0, s, wordSet);
    }

    private:
    unordered_map<int, bool> memo;
    bool dfs(int currIdx, const string& s, const unordered_set<string>& wordSet)
    {
        if (currIdx == s.length()) {
            memo[currIdx] = true;
            return true;
        }

        if (memo.count(currIdx)) return memo[currIdx];

        for (auto& word : wordSet) {
            if (s.substr(currIdx, word.length()) == word) {
                if (dfs(currIdx+word.length(), s, wordSet)) {
                    memo[currIdx] = true;
                    return true;
                }
            }
        }
        memo[currIdx] = false;
        return false;
    }
};