

// Time: O(N)
// Space: O(1)

class Solution 
{
    public:
    bool isSubsequence(string s, string t) 
    {
        if (s.length() > t.length()) return false;

        int j = 0;
        for (int i=0; i<t.length(); i++) {
            if (t[i] == s[j]) {
                j++;
            }
        }
        return j == s.length();
    }
};