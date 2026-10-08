class Solution 
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;
        map<vector<int>, vector<string>> lookup;

        auto getMetric = [](const string& s) -> vector<int> {
            vector<int> counts(26, 0);
            for (char ch : s) {
                counts[ch-'a']++;
            }
            return counts;
        };

        for (auto& s : strs) {
            lookup[getMetric(s)].push_back(s);
        }

        for (auto& [_, group] : lookup) {
            res.push_back(group);
        }
        return res;
    }
};