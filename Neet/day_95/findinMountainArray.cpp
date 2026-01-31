class Solution 
{
    public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        int peak = findPeak(,mountainArr, n);

        // search first half first
        int idx = binarySearch(mountainArr, 0, peak, target, true);
        if (idx != -1) return idx;

        return binarySearch(mountainArr, peak, n, target, false);
    }
    private:
    int binarySearch(MountainArray &mountainArr, int left, int right, int target, bool isAscending)
    {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = mountainArr.get(mid);
            if (midVal == target) return mid;

            if (isAscending) {
                if (midVal > target) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else {
                if (midVal > target) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }

            }
        }
        return -1;
    }
    int findPeak(MountainArray &mountainArr, int n)
    {
        int left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right-left) / 2;
            if (mid+1 < n && mountainArr.get(mid) < mountainArr.get(mid+1)) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};