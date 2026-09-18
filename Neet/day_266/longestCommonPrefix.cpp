class Solution 
{
    public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.empty()) return "";

        int n = strs.size();
        string res = strs[0];
        for (int i=1; i<n; i++) {
            while (strs[i].find(res) != 0) {
                res.pop_back();
            }
        }
        return res;
    }
};