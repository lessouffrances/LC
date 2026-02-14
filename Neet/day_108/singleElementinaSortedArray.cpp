




//         0,1,2,3,4,5,6,7,8
// nums = [1,1,2,3,3,4,4,8,8]

class Solution 
{
    public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int left = 0, right = nums.size()-1; 

        while (left < right) {// 0 < 8  0 < 3
            int mid = left + (right - left) / 2;  // 4  1

            if (mid % 2 != 0) {
                mid -= 1;  // 0
            }
            if (nums[mid] == nums[mid+1]) {
                left = mid+2;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};