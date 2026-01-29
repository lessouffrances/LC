class Solution 
{
    public:
    int minSteps(string s, string t) 
    {
        if (s.length() != t.length()) return 0;

        vector<int>source(26, 0);
        vector<int>target(26, 0);

        int minSteps = 0;
        for (int idx=0; idx<s.length(); idx++) {
            source[s[idx]-'a']++;
            target[t[idx]-'a']++;
        }

        for (int idx=0; idx<26; idx++) {
            minSteps += abs(source[idx] - target[idx]);
        }
        return minSteps/2;
    }
};