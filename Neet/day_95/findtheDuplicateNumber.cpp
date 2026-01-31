




// nums = [1, 3, 4, 2, 2]  n = 4


class Solution 
{
    public:
    int findDuplicate(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        int left = 1, right = n-1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;

            for (int num : nums) {
                if (num < mid) {
                    count++;
                }
            }
            if (count > mid) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        retur left;
    }
};