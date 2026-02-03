class Solution 
{
    public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        if (wordDict.empty() || s.length() == 0) return false;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        vector<int> memo(s.length(), -1); // -1, unvisited, 1 true, 0 false
        return dfs(0, wordSet, s, memo);
    }
    private:
    bool dfs(int idx, unordered_set<string>& wordSet, const string& s, vector<int>& memo)
    {
        if (idx == s.length()) return true;
        if (memo[idx] != -1) return memo[idx];

        for (auto& word : wordSet) {
            int wordLen = word.length();
            if (idx+wordLen > s.length()) continue;

            if (s.substr(idx, wordLen) == word) {
                if (dfs(idx+wordLen, wordSet, s, memo)) {
                    memo[idx] = 1;
                    return true;
                }
            }
        }
        
        memo[idx] = false;
        return false;
    }
};