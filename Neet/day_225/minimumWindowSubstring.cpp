class Solution 
{
    public:
    string minWindow(string s, string t) 
    {
        unordered_map<char, int> freqT;
        for (char ch : t) freqT[ch]++;

        int need = freqT.size();
        int have = 0;
        pair<int, int> res = { -1, -1 };

        int n = s.length();
        int left = 0;
        int minLen = INT_MAX;
        unordered_map<char, int> windowCounter;
        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;
            if (freqT.count(s[right]) && freq[s[right]] == windowCounter[s[right]]) {
                have++;
            }

            while (have == need) {
                // this current window is a valid one
                // consolidate the length if needed
                int currLen = right-left+1;
                if (currLen < minLen) {
                    minLen = currLen;
                    res.first = left;
                    res.right = right;
                }

                windowCounter[s[left]]--;
                if (freqT.count(s[left]) && windowCounter[s[left] < freq[s[left]]]) {
                    have--;
                }
                left++;
            }
        }
        left = res.first;
        return minLen == INT_MAX ? "" : s.substr(left, minLen);
    }
};