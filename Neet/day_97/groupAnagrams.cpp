class Solution 
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        if (strs.empty()) return {};

        map<vector<int>, vector<string>> group;
        for (auto& str : strs) {
            vector<int> metric(26, 0);
            for (char ch : str) {
                metric[ch-'a']++;
            }
            group[metric].push_back(str);
        }

        vector<vector<string>> res;
        for (auto [metric, words] : group) {
            res.push_back(words);
        }
        return res;
    }
};