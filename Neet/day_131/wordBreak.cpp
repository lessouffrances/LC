
// Time: O(N * M * L), 
// where the N is the length of s, M is the number of words in wordSet
// L is the avg length of each word, s.substr()

// Space: O(N + M * L)


class Solution 
{
    public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return dfs(0, s, wordSet);
    }
    private:
    unordered_map<int, int> memo;

    bool dfs(int currIdx, const string& s, unordered_set<string>& wordSet)
    {
        if (currIdx == s.length()) {
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
        