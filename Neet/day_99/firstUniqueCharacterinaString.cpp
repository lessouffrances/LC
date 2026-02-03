class Solution 
{
    public:
    int firstUniqChar(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();

        vector<int> metric(26, 0);
        for (char ch : s) {
            metric[ch-'a']++;
        }

        for (int i=0; i<n; i++) {
            if (metric[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};