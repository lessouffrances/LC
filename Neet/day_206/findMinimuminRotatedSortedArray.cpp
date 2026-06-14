

//               m
//         0,1,2,3,4,5,6
// nums = [4,5,6,7,0,1,2]
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
            // the drop point is somewhere between (mid, right]
            if (nums[mid] > nums[right]) {
                left = mid+1; 
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};