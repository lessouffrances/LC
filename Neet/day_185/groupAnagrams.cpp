// T: O(N * K), where N is the number of words and K is the avg length of each word
// S: O(N * K)

class Solution 
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        if (strs.empty()) return {};

        map<vector<int>, vector<string>> groups;
        for (auto& str : strs) {
            // include positions for 26 lower-case letters
            vector<int> metric(26, 0);
            for (char ch : str) {
                metric[ch-'a']++;
            }
            groups[metric].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& [_, group] : groups) {
            res.push_back(group);
        }
        return res;
    }
};