
// Time: O(log N)
// Space: O(1)

class Solution 
{
    public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        if (arr.empty()) return 0;
        int n = arr.size();

        int left = 0, right = arr.size()-1;
        while (left < right) {
            int mid = left + (right-left) / 2;

            if (mid+1<n && arr[mid] < arr[mid+1]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};