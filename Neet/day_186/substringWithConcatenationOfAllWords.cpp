

class Solution 
{
    public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        // populate all permutations
        dfs(0, words);
        unordered_set<int> res;
        for (auto& perm : allPermuations) {
            int idx = 0;
            while ((idx = s.find(perm, idx)) != string::npos) {
                res.insert(idx);
                idx++;
            }
        }
        vector<int> resList = vector<int>(res.begin(), res.end());
        return resList;
    }

    private:
    vector<string> allPermuations;
    void dfs(int start, vector<string>& words)
    {
        if (start == words.size()) {
            string perm = "";
            for (auto& w : words) perm += w;
            allPermuations.push_back(perm);
            return;
        }

        for (int i=start; i<words.size(); i++) {
            swap(words[i], words[start]);
            dfs(start+1, words);
            swap(words[i], words[start]);
        }
    }
};