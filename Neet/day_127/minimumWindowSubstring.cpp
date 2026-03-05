class Solution 
{
    public:
    string minWindow(string s, string t) 
    {
        if (s.length() < t.length()) return "";
        int n = s.length();

        // build T
        unordered_map<int, int> freqT;
        for (char ch : t) {
            freqT[ch]++;
        }

        int have = 0;
        int need = freqT.size();
        int minLen = INT_MAX;
        pair<int, int> res;

        unordered_mapc<char, int> windowCounter;
        int left = 0;

        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;
            if (freqT.count(s[right]) && freqT[s[right]] == windowCounter[s[right]]) {
                have++;
            }

            while (have > need) {
                if (right-left+1 < minLen) {
                    minLen = right-left+1;
                    res = {left, right};
                }

                windowCounter[s[left]]--;
                if (freqT.count(s[left]) && windowCounter[s[left]] < freqT[s[left]]) {
                    have--;
                }
                left++;
            }
        }
        left = res.first;
        return minLen == INT_MAX ? "" : s.substr(left, minLen);
    }
};