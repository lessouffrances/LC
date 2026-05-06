class Solution 
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        if (strs.empty()) return {};
        map<vector<int>, vector<string>> groups; // metric : { group }

        for (auto& word : strs) {
            vector<int> metric(26, 0);
            for (char ch : word) {
                metric[ch-'a']++;
            }
            groups[metric].push_back(word);
        }

        vector<vector<string>> res;
        for (auto& group : groups) {
            res.push_back(group.second);
        }
        return res;
    }
};