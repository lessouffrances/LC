


// Time: O(log N)
// Space: O(1)
class Solution 
{
    public:
    int findPeakElement(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (mid+1 < n && nnums[mid] < nums[mid+1]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};