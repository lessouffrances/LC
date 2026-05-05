



// Time: O(log N)
// Space: O(1)
class Solution 
{
    public:
    //        m
    //  0,1,2,3,4,5,6
    // [1,2,3,4,5,4,3]
    //  l               
    //              r
    int findPeakElement(vector<int>& nums) 
    {
        if (nums.empty()) return -1;
        int n = nums.size();

        int left = 0, right = n-1;

        while (left < right) {
            int mid = left + (right-left) / 2;
            if (nums[mid] < nums[mid+1]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};