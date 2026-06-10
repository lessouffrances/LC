class Solution 
{
    public:
    int findDuplicate(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        // n+1 numbers
        int n = nums.size()-1;

        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;

            int count = 0;
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }

            if (count > mid) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};