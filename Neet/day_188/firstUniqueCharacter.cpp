class Solution 
{
    public:
    int firstUniqChar(string s) 
    {
        if (s.empty()) return -1;

        unordered_map<int, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        int n = s.length();
        for (int i=0; i<n; i++) {
            if (freq[s[i]] == 1) return i;
        }
        return -1;
    }
};