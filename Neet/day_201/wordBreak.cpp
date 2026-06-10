class Solution 
{
    public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        if (s.length() == 0) return false;
        if (wordDict.empty()) return false;

        // just change a type, get rid of duplicates
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        return dfs(0, s, wordSet);
    }

    private:
    unordered_map<int, int> memo; // { currIdx, bool }
    bool dfs(int currIdx, const string& s, unordered_set<string>& wordSet)
    {
        // base case:
        if (currIdx == s.length()) {
            return true;
        }

        // early-return
        if (memo.count(currIdx)) return memo[currIdx];

        for (auto& word : wordSet) {
            // this is the only condition that we can proceed
            // template explained: s.substr(startPos, size)
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