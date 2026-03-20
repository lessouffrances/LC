class Solution 
{
    public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        if (words.empty()) return {};

        unordered_set<string> wordSet(words.begin(), words.end());

        vector<string> res;
        for (auto& w : words) {
            memo.clear();
            if (dfs(0, 0, w, wordSet)) {
                res.push_back(w);
            }
        }
        return res;
    }

    private:
    unordered_map<int, bool> memo;

    bool dfs(int count, int currIdx, 
        const string& word, unordered_set<string>& wordSet) 
    {
        // can be broken into >= 2 words in the given lists
        if (currIdx == word.length() && count >= 2) {
            memo[currIdx] = true;
            return true;
        } 

        // check memo
        if (count >= 1 && memo.count(currIdx)) return memo[currIdx];

        // words can be reused
        for (auto& w : wordSet) {
            // this is the only condition to proceed
            if (word.substr(currIdx, w.length()) == w) {
                if (dfs(count+1, currIdx+w.length(), word, wordSet)) return true;
            }
        }

        if (count >= 1 ) memo[currIdx] = false;
        return false;
    }
};