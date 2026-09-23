class Solution 
{
    public:
    string addStrings(string num1, string num2) 
    {
        if (num1.length() == 0) return num2;
        if (num2.length() == 0) return num1;

        int m = num1.length(), n = num2.length();
        int i=m-1, j=n-1;
        

        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += num1[i]-'0';
                i--;
            }
            if (j >= 0) {
                sum += num2[j]-'0';
                j--;
            }

            int digit = sum % 10;
            carry = sum / 10;
            res += to_string(digit);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};