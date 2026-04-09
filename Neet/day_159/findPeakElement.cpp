


// Time: O(N logN)
// Space: O(1)

class Solution 
{
    public:
    int findPeakElement(vector<int>& nums) 
    {
        if (nums.empty()) return -1;
        int n = nums.size();

        int left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right-left)/2;

            if (mid+1<n && nums[mid] < nums[mid+1]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};