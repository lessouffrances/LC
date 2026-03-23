


// Time: O(log N)
// Space: O(1)
class Solution 
{
    public:
    int mySqrt(int x) 
    {
        if (x == 0 || x == 1) return x;

        int left = 1, right = x/2;

        int res = 0;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if ((long long) mid * mid <= x) {
                res = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return res;
    }
};