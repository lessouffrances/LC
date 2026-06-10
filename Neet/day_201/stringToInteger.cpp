class Solution 
{
    public:
    int myAtoi(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();

        int i = 0;
        // skip all spaces
        while (i < n && s[i] == ' ') i++;

        int sign = 1;
        if (i < n && s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        // skip all leading zeros
        while (i < n && s[i] == '0') i++;

        long long res = 0;
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            if (sign * res > INT_MAX) return INT_MAX;
            if (sign * res < INT_MIN) return INT_MIN;
            i++;
        }
        return sign * res;
    }
};