class Solution 
{
    public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        if (s.length() == 0) return {};

        unordered_set<string>wordSet(wordDict.begin(), wordDict.end());
        vector<string> startPath;
        dfs(0, startPath, s, wordSet);
        return res;
    }
    private:
    vector<string> res;
    void dfs(int idx, vector<string>& currPath, const string& s, unordered_set<string>& wordSet)
    {
        if (idx == s.length()) {
            res.push_back(merge(currPath));
            return;
        }

        for (auto& w : wordSet) {
            if (idx + w.length() <= s.length() && s.substr(idx, w.length()) == w) {
                currPath.push_back(w);
                dfs(idx+w.length(), currPath, s, wordSet);
                currPath.pop_back();
            }
        }
    }

    string merge(vector<string>& path)
    {
        int n = path.size();
        string res = "";
        for (int i=0; i<n-1; i++) {
            res += (path[i] + ' ');
        }
        res += path[n-1];
        return res;
    }
};