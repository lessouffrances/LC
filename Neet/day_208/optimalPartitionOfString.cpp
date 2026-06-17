class Solution 
{
    public:
    int partitionString(string s) 
    {
        int minRes = 1;
        int n = s.length();
        unordered_set<char> seen;

        for (int i=0; i<n; i++) {
            if (seen.count(s[i])) {
                minRes++;
                seen.clear();
                seen.insert(s[i]);
            } else {
                seen.insert(s[i]);
            }
        }
        return minRes;
    }
};