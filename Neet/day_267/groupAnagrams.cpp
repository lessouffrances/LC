class Solution 
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        if (strs.empty()) return {};

        map<vector<int>, vector<string>> groups;
        for (auto& str : strs) {
            groups[getMetric(str)].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& [_, group] : groups) {
            res.push_back(group);
        }
        return res;
    }

    private:
    vector<int> getMetric(const string& s)
    {
        vector<int> metric(26, 0);
        for (char ch : s) {
            metric[ch-'a']++;
        }
        return metric;
    }
};