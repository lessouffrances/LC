class Solution 
{
    public:
    bool isAnagram(string s, string t) 
    {
        if (s.length() != t.length()) return false;
        int n = s.length();

        vector<int>counter1(26, 0);
        vector<int>counter2(26, 0);

        for (int i=0; i<n; i++) {
            counter1[s[i]-'a']++;
            counter2[t[i]-'a']++;
        }
        return counter1 == counter2;
    }
};