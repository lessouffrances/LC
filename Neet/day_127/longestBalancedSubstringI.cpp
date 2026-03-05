class Solution 
{
    public:
    int longestBalanced(string s) 
    {
        int n = s.length();
        int maxLen = 0;
        vector<int> windowCounter(26);

        for (int start=0; start<n; start++) {
            // reset counter
            fill(windowCounter.begin(), windowCounter.end(), 0);

            // fill the counter using this end loop!
            for (int end=start; end<n; end++) {
                int counterIdx = s[end]-'a';
                windowCounter[counterIdx]++;

                int target = windowCounter[counterIdx];
                bool isBalanced = true;
                for (int count : windowCounter) {
                    // the != 0 is important! 
                    // becasue there must be some irrelevant 0
                    if (count != 0 && count != target) {
                        isBalanced = false;
                        break;
                    }
                }
                if (isBalanced) maxLen = max(maxLen, end-start+1);
            }
        }
        return maxLen;
    }
};