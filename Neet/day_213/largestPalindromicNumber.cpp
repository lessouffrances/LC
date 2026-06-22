class Solution 
{
    public:
    string largestPalindromic(string num) 
    {
        vector<int> freq(10, 0);
        for (char ch : num) freq[ch-'0']++;

        string left = "";
        char mid = ' ';

        // build left half greedy from the largest digit
        // greedily go from the largest digit
        for (int digit=9; digit>=0; digit--) {
            if (freq[digit] >= 2) {
                left += string(freq[digit]/2, '0'+digit);
            }
            // the mid == ' ' check is for reserving mid for the largest digit possible
            if (freq[digit] % 2 == 1 && mid == ' ') {
                mid = '0'+digit;
            }
        }

        // edge case: what if leading zeros occur
        if (!left.empty() && left[0] == '0') {
            if (mid != ' ') return string(1, mid);
            return "0";
        }

        string right = left;
        reverse(right.begin(), right.end());
        if (mid != ' ') return left + mid + right;
        return left + right;
    }
};