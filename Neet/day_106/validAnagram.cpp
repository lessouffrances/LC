








class Solution 
{
    public:
    bool isAnagram(string s, string t) 
    {
        if (s.length() != t.length()) return false;
        int n = s.length();

        vector<int> sCounter(26, 0);
        vector<int> tCounter(26, 0);
        for (int i=0; i<n; i++) {
            sCounter[s[i]-'a']++;
            tCounter[t[i]-'a']++;
        }

        return sCounter == tCounter;
    }
};