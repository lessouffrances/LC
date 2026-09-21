
//         
// s = "cbaebabacd", p = "abc"

class Solution 
{
    public:
    vector<int> findAnagrams(string s, string p) 
    {
        // find all anagrams of p in s
        if (p.length() > s.length()) return {};
        int n = s.length();

        unordered_map<char, int> benchmark;
        for (char ch : p) benchmark[ch]++;

        int k = p.length();
        vector<int> res;
        // maintain a sliding window of length p.len
        unordered_map<char, int> windowCounter;
        for (int end=0; end<n; end++) {
            windowCounter[s[end]]++;
            if (end >= k) {
                windowCounter[s[end-k]]--;
                if (windowCounter[s[end-k]] == 0) {
                    windowCounter.erase(s[end-k]);
                }
            }
            if (windowCounter == benchmark) {
                res.push_back(end-k+1);
            } 
        }
        return res;
    }
};