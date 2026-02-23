






class Solution 
{
    public:
    string minWindow(string s, string t) 
    {
        if (t.length() > s.length()) return "";
        int n = s.length();

        // build target map
        unordered_map<char, int> freqT;
        for (char ch : t) {
            freqT[ch]++;
        }
        
        int need = freqT.size();
        int have = 0;

        int left = 0;
        int minLen = INT_MAX;
        pair<int, int> idxes; // { left, right }
        unordered_map<char, int> windowCounter;
        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;

            // increment 'have' when:
            if (freqT.count(s[right]) && windowCounter[s[right]] == freqT[s[right]]) {
                have++;
            }
            
            // shrink the window when:
            while (have >= need) {
                if (right-left+1 < minLen) {
                    minLen = right-left+1;
                    idxes = {left, right};
                }

                windowCounter[s[left]]--;
                if (freqT.count(s[left]) && windowCounter[s[left]] < freqT[s[left]]) {
                    have--;
                }
                left++;
            }
        }
        left = idxes.first;
        return minLen == INT_MAX ? "" : s.substr(left, minLen);
    }
};