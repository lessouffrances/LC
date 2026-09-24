class Solution 
{
    public:
    int findMin(vector<int>& nums) 
    {
        if (nums.empty()) return -1;
        int n = nums.size();

        int left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] > nums[right]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};