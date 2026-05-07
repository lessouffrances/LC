class Solution 
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        if (strs.empty()) return {};

        map<vector<int>, vector<string>> record;
        for (auto& word : strs) {
            vector<int> metric(26);
            for (char ch : word) {
                metric[ch-'a']++;
            }
            record[metric].push_back(word);
        }

        vector<vector<string>> res;
        for (auto& [metric, words] : record) {
            res.push_back(words);
        }
        return res;
    }
};