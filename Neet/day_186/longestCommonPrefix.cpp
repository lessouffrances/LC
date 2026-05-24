class Solution 
{
    public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string prefix = strs[0];
        for (auto& str : strs) {
            while (str.find(prefix) != 0) {
                prefix.pop_back();
            }
        }
        return prefix;
    }
};