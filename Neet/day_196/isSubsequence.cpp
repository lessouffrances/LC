class Solution 
{
    public:
    bool isSubsequence(string s, string t) 
    {
        if (s.length() > t.length()) return false;

        int i=0; 
        for (int j=0; j<t.length(); j++) {
            if (s[i] == t[j]) i++;
        }
        return i == s.length();
    }
};