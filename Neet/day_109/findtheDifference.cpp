class Solution 
{
    public:
    char findTheDifference(string s, string t) 
    {
        vector<int>tCounter(26, 0);
        for (char ch : t) {
            tCounter[ch-'a']++;
        }

        for (char ch : s) {
            tCounter[ch-'a']--;
        }

        for (int i=0; i<26; i++) {
            if (tCounter[i] > 0) {
                return 'a' + i;
            }
        }
        return '*';
    }
};