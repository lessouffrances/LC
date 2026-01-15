class Solution 
{
    public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        if (s.empty() || wordDict.empty()) return {};

        target = s;
        dict = wordDict;

        vector<string> path;
        dfs(0, path);
        return res;
    }
    private:
    string target;
    vector<string> dict;
    vector<string> res;
    void dfs(int pos, vector<string>& path)
    {
        // hits the target length
        if (pos == target.length()) {
            res.push_back(join(path));
            return;
        }

        for (auto& word : dict) {
            if (target.substr(pos, word.length()) == word) {
                path.push_back(word);
                dfs(pos + word.length(), path);
                path.pop_back(); // backtrack
            }
        }
    }

    string join(const vector<string>& words)
    {
        if (words.empty()) return "";

        string res = words[0];
        for (int i=1; i<words.size(); i++) {
            res += " " + words[i];
        }
        return res;
    }
};