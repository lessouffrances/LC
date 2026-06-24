class Solution 
{
    public:
    string largestPalindromic(string num) 
    {
        if (num.length() == 0) return "";
        int n = num.size();

        // count freq
        vector<int> freq(10, 0);
        for (char ch : num) freq[ch-'0']++;

        string left = "";
        char mid = ' '; // if there's once a odd number of char, assign it to mid
        // greedily go from the largest digit
        for (char digit='9'; digit>='0'; digit--) {
            if (freq[digit-'0'] > 0 && freq[digit-'0'] % 2 == 0) {
                left += string(freq[digit-'0']/2, digit);

            } else if (freq[digit-'0'] > 0 && freq[digit-'0'] % 2 == 1) {
                left += string(freq[digit-'0']/2, digit);
                if (mid == ' ') mid = digit;
            }
        }

        // edge case: if there's leading zeroes
        if (!left.empty() && left[0] == '0') {
            if (mid != ' ') return string(1, mid);
            return "0";
        }
        string right = left;
        reverse(right.begin(), right.end());
        if (mid != ' ') return left+mid+right;
        return left+right;
    }
};