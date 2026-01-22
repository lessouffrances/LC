// 0 1 2 4 5 6 7


// 0 1 2 3 4 5 6
// 4 5 6 7 0 1 2

class Solution 
{
    public:
    int findMin(vector<int>& nums) 
    {
        int left = 0, right = nums.size()-1; // l=0; r=6


        while (left < right) { // 0<6  4<6  4<5
            int mid = left + (right - left) / 2; // 3  5  4
            if (nums[mid] > nums[right]) { // t f f f
                left = mid+1; // 4
            } else {
                right = mid; // 5 4
            }
        }
        return nums[right];
    }
};