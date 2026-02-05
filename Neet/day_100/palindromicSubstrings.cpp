










class Solution 
{
    public:
    int countSubstrings(string s) 
    {
        int n = s.length();

        for (int i=0; i<n; i++) {
            updatePalindromes(s, i, i, n);
            updatePalindromes(s, i, i+1, n);
        }

        return count;
    }

    private:
    int count = 0;
    void updatePalindromes(string& s, int left, int right, int n)
    {
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 >= 2) {
                count++;
            }
            left--;
            right++;
        }
    }
};