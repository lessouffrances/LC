class Solution 
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        if (strs.empty()) return {};
        unordered_map<vector<int>, vector<string>> groups;

        for (auto& word : strs) {
            vector<int> metric(26);
            for (char ch : word) {
                metric[ch-'a']++;
            }
            groups[metric].push_back(word);
        }

        vector<vector<string>> res;
        for (auto& [ _, group] : groups) {
            res.push_back(group);
        }
        return res;
    }
};