class Solution 
{
    public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.empty()) return "";

        string benchmark = strs[0];
        int n = strs.size();
        for (int i=1; i<n; i++) {
            while (strs[i].find(benchmark) != 0) {
                benchmark.pop_back();
            }
        }
        return benchmark;
    }
};