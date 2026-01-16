class Solution 
{
    public:
    string minWindow(string s, string t) 
    {
        if (t == "") return "";

        unordered_map<char, int> freqT;
        unordered_map<char, int> window;
        
        // build the benchmark map
        for (char c : t) {
            freqT[c]++;
        }

        int have = 0;
        int need = freqT.size();

        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;

        int l = 0;
        for (int r=0; r<s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (freqT.count(c) && freqT[c] == window[c]) {
                have++;
            }

            while (have == need) {
                // udpate result
                if (r-l+1 < resLen) {
                    res = {r, l};
                    resLen = r=l+1;
                }

                // shrink window
                window[s[l]]--;
                if (freqT.count(s[l]) && window[s[l]] < freqT[l]) {
                    have--;
                }
                l++;
            }
        }

        l = res.first;
        int r = res.second;

        return res == INT_MAX ? "" : string(s.begin()+l, s.begin()+r+1);
    }
};