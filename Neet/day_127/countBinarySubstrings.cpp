class Solution 
{
    public:
    int countBinarySubstrings(string s) 
    {
        int n = s.length();
        int totalCount = 0;
        for (int i=0; i<n; i++) {
            if (s[i-1] == '0' && s[i] == '1') {
                totalCount += countBinarySubstringsHelper(s, s[i-1], '0', s[i], '1');
            } else if (s[i-1] == '1' && s[i] == '0') {
                totalCount += countBinarySubstringsHelper(s, s[i-1], '1', s[i], '0');
            }
        }
        return count;
    }
    private:
    int countBinarySubstringsHelper(const string& s, 
        int left, char lc, int right, char rc) 
    {
        int n = s.length();
        int counter = 0;

        while (left>=0 && right<n && s[left] == lc && s[right] == rc) {
            counter++;
            left--;
            right++;
        }
        return counter;
    }
};