// T: O( max(N, M) )
// S: O( max(N, M) )

class Solution 
{
    public:
    string addStrings(string num1, string num2) 
    {
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;

        int i=num1.size()-1;
        int j=num2.size()-1;

        string res = "";
        int carry = 0;
        while (i>=0 || j>=0 || carry) {
            int sum = carry;
            if (i>=0) {
                sum += num1[i] - '0';
                i--;
            }
            if (j>=0) {
                sum += num2[j] - '0';
                j--;
            }

            int digit = sum % 10;
            carry = sum / 10;
            res = to_string(digit) + res;
        }
        return res;
    }
};