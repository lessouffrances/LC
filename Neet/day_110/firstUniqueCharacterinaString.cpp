class Solution 
{
    public:
    int firstUniqChar(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();

        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        for (int i=0; i<n; i++) {
            if (freq[s[i]] == 1) return i;
        }
        return -1;
    }
};