//      0,1,2,3,4,5,6,7,8,9,10,11,12
// s = "A D O B E C O D E B A N C", t = "ABC"
//                        l
//                              r
// have = 3
// need = 3
// freq = { {'A',1}, {'B',1}, {'C',1} }
// currLen = 6
// res = {0, 5}

class Solution 
{
    public:
    string minWindow(string s, string t) 
    {
        // build the freq for t
        unordered_map<char, int> freq;
        for (char ch : t) {
            freq[ch]++;
        }

        int need = freq.size();
        int have = 0;
        pair<int, int> res = {-1, -1};

        int n = s.length();
        int left = 0;
        int minLen = INT_MAX;
        unordered_map<char, int> windowCounter;
        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;
            if (freq.count(s[right]) && freq[s[right]] == windowCounter[s[right]]) {
                have++;
            }

            while (have == need) {
                // this current window is a valid one
                int currLen = right-left+1;
                if (currLen < minLen) {
                    minLen = currLen;
                    res.first = left;
                    res.second = right;
                }
                windowCounter[s[left]]--;
                if (freq.count(s[left]) && windowCounter[s[left]] < freq[s[left]]) {
                    have--;
                }
                left++;
            }
        }

        left = res.first;
        return (minLen == INT_MAX) ? "" : s.substr(left, minLen);
    }
};