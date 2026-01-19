class Solution 
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        if (strs.empty()) return {};

        map<vector<int>, vector<string>> lookUp;
        for (auto& str : strs) {
            vector metric(26, 0);
            for (char ch : str) {
                metric[ch-'a']++;
            }
            lookUp[metric].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& [metric, strs] : lookUp) {
            res.push_back(strs);
        }

        return res;
    }
};