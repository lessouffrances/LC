class Solution 
{
    public:
    string minWindow(string s, string t) 
    {
        if (t == "") return "";

        int n = s.length();
        unordered_map<char, int> freqT;
        unordered_map<char, int> windowCounter;

        // freqT is the benchmark
        for (char ch : t) {
            freqT[ch]++;
        }

        int have = 0;
        int need = freqT.size();

        pair<int, int> resIdxes = {-1, -1};
        int resLen = INT_MAX;

        int left = 0;
        for (int right=0; right<n; right++) {
            char ch = s[right];
            windowCounter[ch]++;

            if (freqT.count(ch) && freqT[ch] == windowCounter[ch]) {
                have++;
            }
            while (have == need) {
                if (right-left+1 < resLen) {
                    resIdxes = {left, right};
                    resLen = right-left+1;
                }

                windowCounter[s[left]]--;
                if (freqT.count(s[left]) && windowCounter[s[left]] < freqT[s[left]]) {
                    have--;
                }
                left++;
            }
        }

        left = resIdxes.first;
        int right = resIdxes.second;

        return (resLen == INT_MAX) ? "" : string(s.begin()+left, s.begin()+right+1);
    }
};