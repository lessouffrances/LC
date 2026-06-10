class Solution 
{
    public:
    string largestOddNumber(string num) 
    {
        if (num.length() == 0) return "";
        int n = num.length();

        for (int i=n-1; i>=0; i--) {
            if ( (num[i]-'0') % 2 != 0) {
                return string(num.begin(), num.begin()+i+1);
            }
        }
        return "";
    }
};