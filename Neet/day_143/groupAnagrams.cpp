



class Solution 
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        if (strs.empty()) return {};

        map<vector<int>, vector<string>> groups;

        for (auto& str : strs) {
            vector<int> metric(26, 0);
            for (char ch : str) {
                metric[ch-'a']++;
            }
            groups[metric].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& [_ , group] : groups) {
            res.push_back(group);
        }
        return res;
    }
};