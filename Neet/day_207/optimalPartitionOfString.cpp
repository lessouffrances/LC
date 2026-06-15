class Solution 
{
    public:
    int partitionString(string s) 
    {
        if (s.length() == 0) return 0;

        int n = s.length();
        int count = 1;

        unordered_set<char> windowSet;
        for (int i=0; i<n; i++) {
            if (!windowSet.count(s[i])) {
                windowSet.insert(s[i]);
            } else {
                windowSet.clear();
                windowSet.insert(s[i]);
                count++;
            }
        }
        return count;
    }
};