class Solution 
{
    public:
    int minSteps(string s, string t) 
    {
        // build 26 metric for both
        vector<int> sourceMetric(26, 0);
        vector<int> targetMetric(26, 0);
        int n = s.length();

        for (int i=0; i<n; i++) {
            sourceMetric[s[i]-'a']++;
            targetMetric[t[i]-'a']++;
        }

        int steps = 0;
        for (int i=0; i<26; i++) {
            steps += abs(sourceMetric[i]-targetMetric[i]);
        }

        return steps / 2;
    }
};