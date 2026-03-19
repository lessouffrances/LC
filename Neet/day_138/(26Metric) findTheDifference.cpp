

// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    char findTheDifference(string s, string t) 
    {
        vector<int> sCounter(26, 0);
        vector<int> tCounter(26, 0);

        for (char ch : s) {
            sCounter[ch-'a']++;
        }
        for (char ch : t) {
            tCounter[ch-'a']++;
        }

        for (int i=0; i<26; i++) {
            if (sCounter[i] != tCounter[i]) {
                return 'a' + i;
            }
        }
        return 0;
    }
};