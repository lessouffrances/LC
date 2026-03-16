


// Time: O(n · 2^n) worst case

// In the worst case (e.g. s = "aaa...", wordDict = ["a", "aa", "aaa", ...]), 
// the number of ways to segment grows exponentially — up to 2^n paths
// Each path takes O(n) to merge
// Per node: iterating over wordSet is O(W) where W = dict size, 
// substr comparison is O(L) where L = avg word length → O(W · L) per node, 
// but this is typically treated as a constant relative to n

// Space: O(n · 2^n)
// res stores up to 2^n sentences each of length O(n)
// Recursion stack: O(n) depth
// currPath: O(n)
class Solution 
{
    public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        if (wordDict.empty() || s.length() == 0) return {};

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> currPath;
        dfs(0, currPath, s, wordSet);
        return res;
    }
    
    private:
    vector<string> res;

    void dfs(int currIdx, vector<string>& currPath, 
        const string& s, unordered_set<string>& wordSet)
    {
        if (currIdx == s.length()) {
            res.push_back(merge(currPath));
            return;
        }

        for (auto& word : wordSet) {
            // this is the only condition to proceed
            if (s.substr(currIdx, word.length()) == word) {
                currPath.push_back(word);
                dfs(currIdx+word.length(), currPath, s, wordSet);
                currPath.pop_back();
            }
        }
    }

    string merge(vector<string>& path)
    {
        int n = path.size();
        string res = "";
        for (int i=0; i<n-1; i++) {
            res += path[i] + ' ';
        }
        res += path[n-1];
        return res;
    }
};