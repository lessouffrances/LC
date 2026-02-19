



// "c  c  a  a  b  b  b"
//        l             r
// counter = {{a,2},{b,3},{}}
// maxLen = 3
class Solution 
{
    public:
    int lengthOfLongestSubstringTwoDistinct(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();

        unordered_map<char, int> windowCounter;
        int maxLen = 0;
        int left = 0;
        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;

            while (windowCounter.size() > 2) {
                if (windowCounter.count(s[left])) {
                    windowCounter[s[left]]--;
                    if (windowCounter[s[left]] == 0) {
                        windowCounter.erase(s[left]);
                    }
                }
                left++;
            } 
            maxLen = max(maxLen, right-left+1);
        }
        
        return maxLen;
    }
};