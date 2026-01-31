class Solution 
{
    public:
    int mySqrt(int x) 
    {
        if (x == 1 || x == 0) return x;
        int left = 0, right = x / 2;
        int res = 0;

        while (left <= right) {
            int mid = left + (right-left) / 2;

            if ((long long)mid*mid <= (long long)x) {
                res = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return res;
    }
};