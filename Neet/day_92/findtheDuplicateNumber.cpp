class Solution 
{
    public:
    int findDuplicate(vector<int>& nums) 
    {
        if (nums.empty()) return -1;
        int n = nums.size();

        int left = 1, right = n-1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;

            for (int num : nums) {
                if (num <= mid) count++;
            }
            if (count > mid) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return right;
    }
};