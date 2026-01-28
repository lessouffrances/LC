

// [0,2,3,4,5,10,9,0]
// [0,2,10,9,8,7,6,0]


class Solution 
{
    public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        if (arr.empty()) return -1;
        int n = arr.size();

        int left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid+1]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};