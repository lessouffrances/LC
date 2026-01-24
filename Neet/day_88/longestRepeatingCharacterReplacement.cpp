class Solution 
{
    public:
    int characterReplacement(string s, int k) 
    {
        if (s.length() == 0) return 0;

        int left = 0;
        int n = s.length();
        unordered_map<char, int> windowCounter;
        int maxLen = INT_MIN;

        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;
            //find the most freq char in the current window
            auto maxPair = *max_element(windowCounter.begin(), windowCounter.end(), [](const auto& a, const auto& b){
                return a.second < b.second;
            })
            int highestFreq = maxPair.second;

            // if the diff is larger than k, shift the left pointer
            while ((right-left+1) - highestFreq > k) {
                windowCounter[s[left]]--;
                if (windowCounter[s[left]] == 0) {
                    windowCounter.erase(s[left]);
                }
                left++;

                // update the highestFreq as the window shrinks
                auto maxPair = *max_element(windowCounter.begin(), windowCounter.end(), [](const auto& a, const auto& b){
                    return a.second < b.second;
                })
                highestFreq = maxPair.second;
            }

            maxLen = max(maxLen, (right-left+1));
        }
        return maxLen;
    }
};