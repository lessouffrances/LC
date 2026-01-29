

//         0 1 2 3 4 5 6
// nums = [4,5,6,7,0,1,2] 


class Solution 
{
    public:
    int search(vector<int>& nums, int target) 
    {
        if (nums.empty()) return -1;
        int n = nums.size(); //7

        int l = 0, r = n-1; //l=0, r=6
        while (l <= r) {// 0<6
            int mid = l + (r - l) / 2;// m=3

            if (nums[mid] == target) return mid;

            // check which half is sorted
            if (nums[l] <= nums[mid]) {
                // left half is sorted
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            } else {
                // right half is sorted
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};