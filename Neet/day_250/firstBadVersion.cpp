// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
    public:
    int firstBadVersion(int n) 
    {
        if (n == 0) return n;
        
        int left = 1, right = n;
        int res = -1;
        // find the leftmost bad version
        while (left <= right) {
            int mid = left + (right-left)/2;

            if (isBadVersion(mid)) {
                res = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return res;
    }
};