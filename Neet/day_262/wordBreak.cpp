class Solution 
{
    public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return dfs(0, s, wordSet);
    }
    private:
    unordered_map<int, bool> memo;
    bool dfs(int currIdx, const string& s, unordered_set<string> wordSet)
    {
        // base case
        if (currIdx == s.length()) return true;
        if (memo.count(currIdx)) return memo[currIdx];

        for (auto& word : wordSet) {
            if (s.substr(currIdx, word.length()) != word) continue;
            if (dfs(currIdx+word.length(), s, wordSet)) {
                memo[currIdx] = true;
                return true;
            }
        }
        memo[currIdx] = false;
        return false;
    }
};