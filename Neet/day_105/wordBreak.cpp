class Solution 
{
    public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        string startPath = "";
        return dfs(0, startPath, s, wordSet);
    }
    private:
    unordered_map<int, bool> memo;
    bool dfs(int idx, string& currPath, string s,  set<string>& wordSet)
    {
        if (currPath == s) return true;

        if (memo.count(idx)) return memo[idx];

        for (auto& word : wordSet) {
            if (idx + word.length() > s.length()) continue;
            if (word != s.substr(idx, word.length())) continue;

            currPath += word;
            if (dfs(idx + word.length(), currPath, s, wordSet)) {
                memo[idx + word.length()] = true;
                return true;
            }

            currPath.erase(currPath.length() - word.length());
        }
        memo[idx] = false;
        return false;
    }
};