class Solution 
{
    public:
    // since there is this substring that must have each letter from t,
    // we will need to create a frequency map for t.
    // the sliding rule: when need == have, we can shrink the window

    string minWindow(string s, string t) 
    {
        if (s.length() < t.length()) return "";

        // build freqT
        unordered_map<char, int> freqT;
        for (char ch : t) {
            freqT[ch]++;
        }

        int have = 0;
        int need = freqT.size(); // how many distinct letter we need
        pair<int, int> res; // {left, right}
        int minLen = INT_MAX;
        unordered_map<char, int> windowCounter;

        int left = 0;
        int n = s.length();
        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;

            if (freqT.count(s[right]) && windowCounter[s[right]] == freqT[s[right]]) {
                have++;
            }

            while (have == need) {
                // update because this window is valid
                int currLen = right-left+1;
                if (currLen < minLen) {
                    minLen = currLen;
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
        return (minLen == INT_MAX) ? "" : s.substr(left, minLen);
    }
};