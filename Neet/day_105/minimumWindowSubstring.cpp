class Solution 
{
    public:
    string minWindow(string s, string t) 
    {
        unordered_map<char, int> freqT;
        unordered_map<char, int> windowCounter;

        // build freqT
        for (char ch : t) {
            freqT[ch]++;
        }

        int have = 0;
        int need = freqT.size();
        pair<int, int> res;
        int resLen = INT_MAX;

        int n = s.length();
        int left = 0;
        for (int right=0; right<n; right++) {
            char ch = s[right];
            windowCounter[s[right]]++;

            if (freqT.count(ch) && freqT[ch] == windowCounter[ch]) {
                have++;
            }

            while (have >= need) {
                if (right-left+1 < resLen) {
                    res = {left, right};
                    resLen = right-left+1;
                }

                windowCounter[s[left]]--;
                if (freqT.count(s[left]) && windowCounter[s[left]] < freqT[s[left]]) {
                    have--;
                }
                left++;
            }
        }

        left = res.first;
        return (resLen == INT_MAX) ? "" : s.substr(left, resLen);
    }
};