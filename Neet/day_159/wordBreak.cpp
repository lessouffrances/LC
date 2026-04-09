class Solution 
{
    public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return dfs(0, wordSet, s);
    }

    private:
    unordered_map<int, bool> memo;
    
    bool dfs(int currIdx, unordered_set<string>& wordSet, const string& s)
    {
        if (currIdx == s.length()) {
            memo[currIdx] = true;
            return true;
        }

        if (memo.count(currIdx)) return memo[currIdx];

        for (auto& word : wordSet) {
            if (s.substr(currIdx, word.length()) == word) {
                if (dfs(currIdx + word.length(), wordSet, s)) {
                    memo[currIdx+word.length()] = true;
                    return true;
                }
            }
        }

        memo[currIdx] = false;
        return false;
    }
};