class Solution 
{
    public:
    bool canPermutePalindrome(string s) 
    {
        if (s.length() == 0) return true;
        int n = s.length();

        unordered_map<char, int> freq;
        for (int i=0; i<n; i++) {
            freq[s[i]]++;
        }

        bool res = true;
        if (n % 2 != 0) {
            // odd length: one odd, all others are even
            int oddCount = 0;
            for (auto& [ch, count] : freq) {
                if (count % 2 != 0) {
                    oddCount++;
                    if (oddCount > 1) {
                        res = false;
                        return res;
                    };
                } 
            }
            if (oddCount != 1) {
                res = false;
            }

        } else {
            // even length: all are even
            for (auto& [ch, count] : freq) {
                if (count % 2 == 0) continue;
                res = false;
                return res;
            }
        }
        return res;
    }
};