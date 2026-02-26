class Solution 
{
    public:
    int myAtoi(string s) 
    {
        if (s.length() == 0) return 0;

        int i = 0, n = s.length();
        // skip spaces
        while (i < n && s[i] == ' ') i++;

        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        long long res = 0;
        while (i<n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            // prevent overflow:
            if (sign * res > INT_MAX) return INT_MAX;
            if (sign * res < INT_MIN) return INT_MIN;

            i++;
        }
        return sign * res;
    }
};