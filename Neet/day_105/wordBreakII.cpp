class Solution 
{
    public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        if (wordDict.empty()) return {};
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> startPath = {};
        dfs(0, startPath, s, wordSet);
        return res;
    }
    private:
    vector<string> res;
    void dfs(int idx, vector<string>& currPath, const string& s,  set<string>& wordSet)
    {
        if (idx == s.length()) {
            res.push_back(mergeVecToString(currPath));
            return;
        }

        for (auto& word : wordSet) {
            if (idx + word.length() > s.length()) continue;
            if (word != s.substr(idx, word.length())) continue;

            currPath.push_back(word);
            dfs(idx + word.length(), currPath, s, wordSet) ;
            currPath.pop_back(); // backtrack
        }
    }
    string mergeVecToString(vector<string>& words)
    {
        int n = words.size();
        string res = "";
        for (int i=0; i<n-1; i++) {
            res += words[i] + ' ';
        }
        res += words[n-1];
        return res;
    }
};