class Solution 
{
    public:
    string shortestPalindrome(string s) 
    {
        STRING = s;
        int mid = s.length() / 2;
        int n = s.length();

        for (int i = mid; i >= 0; i--) {
            // even-length first (extends further right)
            if (STRING[i] == STRING[i+1]) {
                auto [f2, left2, right2] = isPossiblePalindromeAndIdxes(i, i+1);
                if (left2 == -1) {
                    string suffix = s.substr(right2);
                    return string(suffix.rbegin(), suffix.rend()) + s;
                }
            }

            // odd-length
            auto [flag, left1, right1] = isPossiblePalindromeAndIdxes(i, i);
            if (left1 == -1) {
                string suffix = s.substr(right1);
                return string(suffix.rbegin(), suffix.rend()) + s;
            }
        }
        return s;
    }
    private:
    string STRING;
    //      0 1 2 3   4 5 6 7
    // s = "a a c e   c a a a"
    tuple<bool, int, int> isPossiblePalindromeAndIdxes(int left, int right)
    {
        int n = STRING.length();
        while (left>=0 && right<n && STRING[left] == STRING[right]) {
            left--;
            right++;
        }

        return { true, left, right };
    }
};