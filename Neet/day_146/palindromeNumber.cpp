




// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    bool isPalindrome(int x) 
    {
        if (x < 0) return false;

        // detach digit
        string res = "";
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            res += digit-'0';
        }
        string copy = res;
        reverse(copy.begin(), copy.end());
        return copy == res;
    }
};
        