class Solution 
{
    public:
    string minWindow(string s, string t) 
    {
        if (t.length() > s.length()) return "";

        // builf freq for t
        unordered_map<char, int> freqT;
        for (char ch : t) {
            freqT[ch]++;
        } 

        int need = freqT.size();
        int have = 0;
        int left = 0;
        int n = s.length();
        int minLen = INT_MAX;
        pair<int, int> res = {-1, -1};
        unordered_map<char, int> windowCounter;

        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;
            if (freqT.count(s[right]) && freqT[s[right]] == windowCounter[s[right]]) have++;

            while (have == need) {
                int currLen = right-left+1;
                if (currLen < minLen) {
                    minLen = currLen;
                    res.first = left;
                    res.second = right;
                }

                windowCounter[s[left]]--;
                if (freqT.count(s[left]) && windowCounter[s[left]] < freqT[s[left]]) have--;
                left++;
            }
        }
        left = res.first;
        return (minLen == INT_MAX) ? "" : s.substr(left, minLen);
    }
};