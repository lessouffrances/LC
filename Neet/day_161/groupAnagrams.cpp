


// Time: O(N * 26)
// Space: O(N)
class Solution 
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        if (strs.empty()) return {};
        vector<vector<string>> res;
        map<vector<int>, vector<string>> map;

        for (auto& word : strs) {
            vector<int> identity(26);
            int n = word.length();
            for (int i=0; i<n; i++) {
                identity[word[i]-'a']++;
            }
            map[identity].push_back(word);
        }

        for (auto& [_, group] : map) {
            res.push_back(group);
        }

        return res;
    }
};