class Solution 
{
    public:
    int characterReplacement(string s, int k) 
    {
        if (s.length() == 0) return 0;

        int n = s.length();
        int maxLen = 0;
        unordered_map<int, int> windowFreq;

        int left = 0;
        int maxFreq = 0;
        for (int right=0; right<n; right++) {
            windowFreq[s[right]]++;
            maxFreq = max(maxFreq, windowFreq[s[right]]);

            while ((right-left+1-maxFreq) > k) {
                windowFreq[s[left]]--;
                if (windowFreq[s[left] == 0]) windowFreq.erase(s[left]);
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};