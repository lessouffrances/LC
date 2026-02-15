class Solution 
{
    public:
    int minSteps(string s, string t) 
    {
        vector<int> metricT(26, 0);
        for (char ch : t) {
            metricT[ch-'a']++;
        }

        for (char ch : s) {
            if (metricT[ch-'a'] > 0) metricT[ch-'a']--;
        }

        int count = 0;
        for (int i=0; i<26; i++) {
            count += metricT[i];
        }
        return count;
    }
};