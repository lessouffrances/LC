class Solution 
{
    public:
    vector<int> findAnagrams(string s, string p) 
    {
        if (p.length() > s.length()) return {};
        if (s.length() == 0) return {};

        // p's anagram in s
        int n = s.length();
        int windowLen = p.length();
        unordered_map<char, int> benchmark;
        for (int i=0; i<windowLen; i++) benchmark[p[i]]++;

        // maintain a sliding window
        // 0
        // dhfksubn
        vector<int> res;
        unordered_map<char, int> windowCounter;

        for (int end=0; end<n; end++) {
            windowCounter[s[end]]++;
            if (end > windowLen-1) {
                windowCounter[s[end-windowLen]]--;
                if (windowCounter[s[end-windowLen]] == 0) windowCounter.erase(s[end-windowLen]);
            }
            
            if (windowCounter == benchmark) res.push_back(end-windowLen+1);
        }
        return res;
    }
};