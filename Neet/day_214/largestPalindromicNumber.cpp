class Solution 
{
    public:
    string largestPalindromic(string num) 
    {
        if (num.length() == 0) return "";
        int n = num.size();

        // only has 10 digits
        vector<int> freq(10, 0);
        for (char ch : num) freq[ch-'0']++;

        string left = "";
        char mid = ' ';
        for (int digit=9; digit>=0; digit--) {
            if (freq[digit]>0 && freq[digit] % 2 == 1) {
                left += string(freq[digit]/2, digit+'0');
                if (mid == ' ') mid = digit+'0';
            } else if (freq[digit]>0 && freq[digit] % 2 == 0) {
                left += string(freq[digit]/2, digit+'0');
            }
        }

        // edge case: if theres' leading zeros
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