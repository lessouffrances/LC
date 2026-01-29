class Solution 
{
    public:
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int n = mountainArr.length();
        int peak = findPeak(mountainArr, n);

        // search 0 -> peak 
        int idx = binarySearch(mountainArr, target, 0, peak, true);
        if (idx != -1) return idx;

        return binarySearch(mountainArr, target, peak+1, n-1, false);
    }

    private:
    int binarySearch(MountainArray &arr, int target, int left, int right, bool isAscending)
    {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = arr.get(mid);

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
    
    int findPeak(MountainArray &arr, int n) 
    {
        int left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid+1 < n && arr.get(mid) < arr.get(mid+1)) {
                // peak is in the right
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};