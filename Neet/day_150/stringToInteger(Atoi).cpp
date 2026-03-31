

// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    int myAtoi(string s) 
    {
        if (s.length() == 0) return 0;

        // skip white spaces
        int i = 0;
        while (i<s.length() && s[i] == ' ') i++;

        // see sign
        int sign = 1;
        if (i<s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }
        
        // strip leading 0s
        while (i<s.length() && s[i] == '0') i++;

        long long res = 0;
        while (i<s.length() && isdigit(s[i])) {
            res = res * 10 + (s[i]-'0');

            if (sign * res > INT_MAX) return INT_MAX;
            if (sign * res < INT_MIN) return INT_MIN;

            i++;
        }
        return sign * res;
    }
};