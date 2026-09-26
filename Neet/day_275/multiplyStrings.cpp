//  2  3
//  4  5

//   0123
//     15
//    12
//    10
//    8
//   1035

class Solution 
{
    public:
    string multiply(string num1, string num2) 
    {
        int m = num1.size();
        int n = num2.size();

        vector<int> digits(m+n, 0); 
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                int multiply = (num1[i]-'0') * (num2[j]-'0');
                int p1 = i+j, p2 = i+j+1;
                int sum = multiply + digits[p2];
                digits[p2] = sum % 10;
                digits[p1] += sum / 10;
            }
        }

        string res = "";
        for (int d : digits) {
            if (!(res.empty() && d == 0)) res += to_string(d);
        }
        return res.empty() ? "0" : res;
    }
};