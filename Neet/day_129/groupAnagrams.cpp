class Solution 
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        // invariant: the words that belong to the same word group
        // will have the same 26 counting metric
        map<vector<int>, vector<string>> groups;
        for (auto& str : strs) {
            vector<int> metric = getCountingMetric(str);
            groups[metric].push_back(str);
        } 

        // return
        vector<vector<string>> res;
        for (auto& [_, group] : groups) {
            res.push_back(group);
        }
        return res;
    }
    private:
    vector<int> getCountingMetric(const string& str)
    {
        vector<int> res(26, 0);
        for (char ch : str) {
            res[ch-'a']++;
        }
        return res;
    }
};