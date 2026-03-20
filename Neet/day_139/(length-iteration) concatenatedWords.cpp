class Solution 
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        unordered_set<string> wordSet(words.begin(), words.end());

        vector<string> res;
        for (auto& w : words) {
            memo.clear();
            if (dfs(0, 0, w, wordSet)) res.push_back(w);
        }
        return res;
    }

private:
    unordered_map<int, bool> memo;

    bool dfs(int count, int currIdx, const string& word, unordered_set<string>& wordSet) 
    {
        if (currIdx == (int)word.length()) return count >= 2;
        if (count >= 1 && memo.count(currIdx)) return memo[idx];

        // this iteration will enhance the runtime by much
        for (int len=1; len <= word.length()-currIdx; ++len) {
            if (wordSet.count(word.substr(currIdx, len))) {
                if (dfs(count + 1, currIdx + len, word, wordSet)) return true;
            }
        }

        if (count >= 1) memo[currIdx] = false;
        return false;
    }
};