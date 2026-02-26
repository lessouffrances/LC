


class Solution 
{
    public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        string startPath = "";

        return dfs(0, s, wordSet);
    }
    private:
    // 0 1 2 3
    // l e e t  => code   
    unordered_map<int, int> memo;
    bool dfs(int currIdx, const string& s, unordered_set<string>& wordSet) 
    {
        // base case 
        if (currIdx == s.length()) return true;
        if (memo.count(currIdx)) return memo[currIdx];

        for (auto& word : wordSet) {
            if (s.substr(currIdx, word.length()) == word) {
                // currPath += word;
                if (dfs(currIdx+word.length(), currPath, s, wordSet)) {
                    memp[currIdx+word.length()] = true;
                    return true;
                }
                // currPath.erase(currPath.length() - word.length());
            }
        }
        memo[currIdx] = false;
        return false;
    }
};
