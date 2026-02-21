class Solution 
{
    public:
    int longestBalanced(string s) 
    {
        int n = s.size();
        int maxLen = 0;
        vector<int> freq(26);

        for (int start=0; start<n; start++) {
            // equivalent to initiate a new vector<int> charFreq(26) 
            fill(freq.begin(), freq.end(), 0);

            for (int end=start; end<n; end++) {
                int idx = s[end] - 'a';
                freq[idx]++;
                int target = freq[idx];

                bool isBalanced = true;
                for (int count : freq) {
                    if (count != 0 && count != target) {
                        isBalanced = false;
                        break;
                    }
                }

                if (isBalanced)
                    maxLen = max(maxLen, end-start+1);
            }
        }
        return maxLen;
    }
};