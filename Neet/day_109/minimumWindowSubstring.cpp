class Solution 
{
    public:
    string minWindow(string s, string t) 
    {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> freqT;
        for (char ch : t) {
            freqT[ch]++;
        }

        int need = freqT.size();
        int have = 0;

        int left = 0;
        int n = s.length();
        pair<int, int> res; // left, right
        int resLen = INT_MAX;
        unordered_map<char, int> windowCounter;
        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;

            if (freqT.count(s[right]) && windowCounter[s[right]] == freqT[s[right]]) {
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
        return resLen == INT_MAX ? "" : s.substr(left, resLen);
    }
};