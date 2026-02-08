












class Solution 
{
    public:
    string addBinary(string a, string b) 
    {
        int i = a.length()-1;
        int j = b.length()-1;
        string res = "";

        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            char digit = sum % 2 + '0';
            res = digit + res; // convert to string
            carry = sum / 2;
        }
        
        return res;
    }
};