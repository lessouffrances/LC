







class Solution 
{
    public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) 
    {
        if (queries.empty() || dictionary.empty()) return {};

        set<string>wordSet(dictionary.begin(), dictionary.end());

        vector<string> res;
        for (auto& query : queries) {
            for (auto& word : wordSet) {
                if (query == word || isDiffLessThanTwo(query, word)) {
                    res.push_back(query);
                    break;
                }
            }
        }
        return res;
    }
    private:
    bool isDiffLessThanTwo(const string& s, const string& t) 
    {
        int diff = 0;
        int n = s.length();
        for (int i=0; i<n; i++) {
            if (s[i] != t[i]) diff++;
            if (diff > 2) return false;
        }
        return true;
    }
};