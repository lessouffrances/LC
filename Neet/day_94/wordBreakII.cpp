class Solution 
{
    public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        if (s.length() == 0 || wordDict.empty()) return {};

        vector<string> startPath;
        dfs(startPath, 0, s, wordDict);
        return res;
    }
    private:
    vector<string> res;
    void dfs(vector<string>& currPath, int idx, const string& s, vector<string>& wordDict)
    {
        if (idx == s.length()) {
            res.push_back(join(currPath));
            return;
        }

        for (auto& word : wordDict) {
            if (s.substr(idx, word.length()) == word) {
                currPath.push_back(word);
                dfs(currPath, idx+word.length(), s, wordDict);
                currPath.pop_back(); // backtrack
            }
        }
    }

    string join(vector<string>& path)
    {
        if (path.empty()) return "";

        string res = path[0];
        for (int i=1; i<path.size(); i++) {
            res += " " + path[i];
        }
        return res;
    }    
};