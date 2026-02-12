class Solution 
{
    public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.empty()) return "";

        int n = strs.size();
        string prefix = strs[0];
        for (int i=0; i<n; i++) {
            while (strs[i].find(prefix) != 0) {
                prefix.pop_back();
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};